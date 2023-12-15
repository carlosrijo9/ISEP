use rayon;
use rayon::prelude::*;
use std::sync::mpsc::channel;
use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Instant;
use threadpool::ThreadPool;

#[derive(Clone)]
struct ComplexStruct {
    r: f64,
    i: f64,
}

struct ResultStruct {
    area: f64,
    error: f64,
    numoutside: i32,
}

fn main() {
    let npoints: i32 = 1000;
    let maxiter: i32 = 1000;
    let block_size: i32 = npoints / 10; // Set the block size

    println!(
        "Nr of Points = {:?}\nMax Iterarion = {:?}\nBlock Size = {:?}\n",
        npoints, maxiter, block_size
    );

    // SEQUENTIAL
    //// ITERATORS
    let mut now: Instant = Instant::now();
    let result_seq: ResultStruct = seq_mandel(npoints, maxiter);
    let end_seq: std::time::Duration = now.elapsed();
    println!("Sequential MandelBrot Done!\n");

    //// FOR LOOP
    now = Instant::now();
    let result_for_seq: ResultStruct = for_seq_mandel(npoints, maxiter);
    let end_for: std::time::Duration = now.elapsed();
    println!("Sequential (FOR) MandelBrot Done!\n");

    // THREADPOOL
    //// CELL
    now = Instant::now();
    let result_tp_cell: ResultStruct = mandel_tp_cell(npoints, maxiter);
    let end_tp_cell: std::time::Duration = now.elapsed();
    println!("ThreadPool MandelBrot Cell Done!\n");

    //// LINE
    now = Instant::now();
    let result_tp: ResultStruct = mandel_tp_line(npoints, maxiter);
    let end_tp_line: std::time::Duration = now.elapsed();
    println!("ThreadPool MandelBrot Line Done!\n");

    //// BLOCK
    now = Instant::now();
    let result_tp_block: ResultStruct = mandel_tp_block(npoints, maxiter, block_size);
    let end_tp_block: std::time::Duration = now.elapsed();
    println!("ThreadPool MandelBrot Block Done!\n");

    // RAYON
    now = Instant::now();
    let result_rayon: ResultStruct = mandel_rayon(npoints, maxiter);
    let end_rayon: std::time::Duration = now.elapsed();
    println!("Rayon MandelBrot Done!\n");

    if result_seq.numoutside == result_for_seq.numoutside
        || result_seq.numoutside == result_tp_cell.numoutside
        || result_seq.numoutside == result_tp.numoutside
        || result_seq.numoutside == result_tp_block.numoutside
        || result_seq.numoutside == result_rayon.numoutside
    {
        println!(
            "[SEQ] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_seq.area, result_seq.error, result_seq.numoutside
        );
        println!(
            "[FOR SEQ] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_for_seq.area, result_for_seq.error, result_for_seq.numoutside
        );
        println!(
            "[ThreadPool CELL] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_tp_cell.area, result_tp_cell.error, result_tp_cell.numoutside
        );
        println!(
            "[ThreadPool LINE] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_tp.area, result_tp.error, result_tp.numoutside
        );
        println!(
            "[ThreadPool BLOCK] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_tp_block.area, result_tp_block.error, result_tp_block.numoutside
        );
        println!(
            "[Rayon] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_rayon.area, result_rayon.error, result_rayon.numoutside
        );
    } else {
        println!("Sequential Result = {:?}\n", result_seq.numoutside);
        println!("Sequential FOR Result = {:?}\n", result_for_seq.numoutside);
        println!("ThreadPool Cell Result = {:?}\n", result_tp_cell.numoutside);
        println!("ThreadPool Line Result = {:?}\n", result_tp.numoutside);
        println!(
            "ThreadPool Block Result = {:?}\n",
            result_tp_block.numoutside
        );
        println!("Rayon Result = {:?}\n", result_rayon.numoutside);
        panic!("Result NOK")
    }

    // Print Results
    println!("\n- ==== Performance ==== -\n");
    println!("Sequential MandelBrot = {:?} ms\n", end_seq.as_millis());
    println!(
        "Sequential (FOR) MandelBrot = {:?} ms\n",
        end_for.as_millis()
    );
    println!(
        "ThreadPool MandelBrot Cell = {:?} ms\n",
        end_tp_cell.as_millis()
    );
    println!(
        "ThreadPool MandelBrot Line = {:?} ms\n",
        end_tp_line.as_millis()
    );
    println!(
        "ThreadPool MandelBrot Block = {:?} ms\n",
        end_tp_block.as_millis()
    );
    println!("Rayon MandelBrot = {:?} ms\n", end_rayon.as_millis());
}

// Sequential Mandelbrot - Iterators
fn seq_mandel(npoints: i32, maxiter: i32) -> ResultStruct {
    let numoutside: i32 = (0..npoints)
        .into_iter()
        .map(|i: i32| {
            (0..npoints)
                .into_iter()
                .map(|j| testpoint(i, j, maxiter, npoints))
                .sum::<i32>()
        })
        .sum::<i32>();

    let area =
        2.0 * 2.5 * 1.125 * ((npoints * npoints - numoutside) as f64) / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    let result = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

fn for_seq_mandel(npoints: i32, maxiter: i32) -> ResultStruct {
    let mut numoutside: i32 = 0;

    // Iterating over a grid of points.
    for i in 0..npoints {
        for j in 0..npoints {
            numoutside += testpoint(i, j, maxiter, npoints);
        }
    }

    // Calculating the area and error of the Mandelbrot set.
    let area =
        2.0 * 2.5 * 1.125 * (npoints * npoints - numoutside) as f64 / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    // Returning the result.
    let result = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

fn mandel_tp_cell(npoints: i32, maxiter: i32) -> ResultStruct {
    let n_workers: usize = thread::available_parallelism().unwrap().get();
    let n_jobs = npoints * npoints;
    let pool: ThreadPool = ThreadPool::new(n_workers);
    let (tx, rx) = channel();

    // Iterating over a grid of points.
    for i in 0..npoints {
        for j in 0..npoints {
            let txc = tx.clone();
            pool.execute(move || {
                let local_numoutside = testpoint(i, j, maxiter, npoints);
                txc.send(local_numoutside)
                    .expect("[ThreadPool MandelBrot Cell] Error sending local_numoutside");
            });
        }
    }
    let numoutside = rx.iter().take(n_jobs as usize).fold(0, |a, b| a + b);

    // Calculating the area and error of the Mandelbrot set.
    let area =
        2.0 * 2.5 * 1.125 * (npoints * npoints - numoutside) as f64 / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    // Returning the result.
    let result = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

fn mandel_tp_line(npoints: i32, maxiter: i32) -> ResultStruct {
    let n_workers: usize = thread::available_parallelism().unwrap().get();
    let n_jobs = npoints;
    let pool: ThreadPool = ThreadPool::new(n_workers);
    let (tx, rx) = channel();
    //let mut local_numoutside = 0;

    // Iterating over a grid of points.
    for i in 0..npoints {
        let txc = tx.clone();
        pool.execute(move || {
            let mut local_numoutside = 0;
            for j in 0..npoints {
                local_numoutside += testpoint(i, j, maxiter, npoints);
            }

            txc.send(local_numoutside)
                .expect("[ThreadPool MandelBrot Line] Error sending local_numoutside");
        });
    }
    let numoutside = rx.iter().take(n_jobs as usize).fold(0, |a, b| a + b);

    // Calculating the area and error of the Mandelbrot set.
    let area =
        2.0 * 2.5 * 1.125 * (npoints * npoints - numoutside) as f64 / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    // Returning the result.
    let result = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

fn mandel_tp_block(npoints: i32, maxiter: i32, block_size: i32) -> ResultStruct {
    //let n_jobs = npoints;
    let n_jobs = npoints * npoints;
    //let n_workers: usize = thread::available_parallelism().unwrap().get();
    let pool: ThreadPool = ThreadPool::new(nthreads);
    let (tx, rx) = channel();

    // Iterating over blocks of points.
    for bi in 0..(npoints / block_size) {
        for bj in 0..(npoints / block_size) {
            let i_start = bi * block_size;
            let j_start = bj * block_size;

            // Iterating over points in the block.
            let txc = tx.clone();
            pool.execute(move || {
                for i in i_start..(i_start + block_size) {
                    let mut local_numoutside = 0;
                    for j in j_start..(j_start + block_size) {
                        local_numoutside += testpoint(i, j, maxiter, npoints);
                    }
                    txc.send(local_numoutside)
                        .expect("[ThreadPool MandelBrot Block] Error sending local_numoutside");
                }
            });
        }
    }
    drop(tx);
    let numoutside = rx.iter().take(n_jobs as usize).fold(0, |a, b| a + b);
    //let numoutside = rx.iter().fold(0, |a, b| a + b);

    // Calculating the area and error of the Mandelbrot set.
    let area =
        2.0 * 2.5 * 1.125 * (npoints * npoints - numoutside) as f64 / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    // Returning the result.
    let result: ResultStruct = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

fn mandel_rayon(npoints: i32, maxiter: i32) -> ResultStruct {
    let numoutside: i32 = (0..npoints)
        .into_par_iter()
        .map(|i: i32| {
            (0..npoints)
                .into_par_iter()
                .map(|j| testpoint(i, j, maxiter, npoints))
                .sum::<i32>()
        })
        .sum::<i32>();

    let area =
        2.0 * 2.5 * 1.125 * ((npoints * npoints - numoutside) as f64) / (npoints * npoints) as f64;
    let error = area / npoints as f64;

    let result = ResultStruct {
        area,
        error,
        numoutside,
    };
    result
}

// Auxiliar Functions

fn testpoint(i: i32, j: i32, maxiter: i32, npoints: i32) -> i32 {
    let eps = 1.0e-5;

    let c: ComplexStruct = ComplexStruct {
        r: -2.0 + 2.5 * (i as f64) / (npoints as f64) + eps,
        i: 1.125 * (j as f64) / (npoints as f64) + eps,
    };

    let mut z: ComplexStruct = c.clone();

    for _iter in 0..maxiter {
        let temp = (z.r * z.r) - (z.i * z.i) + c.r;
        z.i = z.r * z.i * 2.0 + c.i;
        z.r = temp;
        if (z.r * z.r + z.i * z.i) > 4.0 {
            return 1;
        }
    }
    return 0;
}
