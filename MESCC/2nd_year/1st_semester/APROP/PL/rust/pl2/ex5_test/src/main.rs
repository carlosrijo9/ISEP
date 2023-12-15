use rayon;
use rayon::prelude::*;
use std::env;
use std::sync::mpsc::channel;
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
    // The first argument is the name of the program itself
    let args: Vec<String> = env::args().collect();

    // Check if at least one argument (other than the program name) is provided
    if args.len() < 5 {
        eprintln!("Usage: cargo run -- <npoints> <maxiter> <blocksize_ratio> <nthreads>");
        std::process::exit(1);
    }

    let mut npoints: i32 = 0;
    let mut maxiter: i32 = 0;
    let mut block_size: i32 = 0;
    let mut nthreads: usize = 0;

    // Skip the first argument (program name) and iterate over the rest
    for (index, argument) in args.iter().skip(1).enumerate() {
        // Parse each string argument into an i32
        let parsed_argument: Result<i32, _> = argument.parse();

        // Check if parsing was successful
        match parsed_argument {
            Ok(value) => {
                // Assign the parsed value to the corresponding variable based on the index
                match index {
                    0 => npoints = value,
                    1 => maxiter = value,
                    2 => block_size = npoints / value,
                    3 => nthreads = value as usize,
                    _ => {
                        eprintln!("Too many arguments provided");
                        std::process::exit(1);
                    }
                }
            }
            Err(err) => {
                eprintln!("Error parsing argument {}: {}", argument, err);
                std::process::exit(1);
            }
        }
    }

    // SEQUENTIAL
    //// ITERATORS
    let mut now: Instant = Instant::now();
    let result_seq: ResultStruct = seq_mandel(npoints, maxiter);
    let end_seq: std::time::Duration = now.elapsed();
    //println!("Sequential MandelBrot Done!\n");

    //// FOR LOOP
    now = Instant::now();
    let result_for_seq: ResultStruct = for_seq_mandel(npoints, maxiter);
    let end_for: std::time::Duration = now.elapsed();
    //println!("Sequential (FOR) MandelBrot Done!\n");

    // THREADPOOL
    //// CELL
    now = Instant::now();
    let result_tp_cell: ResultStruct = mandel_tp_cell(npoints, maxiter, nthreads);
    let end_tp_cell: std::time::Duration = now.elapsed();
    //println!("ThreadPool MandelBrot Cell Done!\n");

    //// LINE
    now = Instant::now();
    let result_tp: ResultStruct = mandel_tp_line(npoints, maxiter, nthreads);
    let end_tp_line: std::time::Duration = now.elapsed();
    //println!("ThreadPool MandelBrot Line Done!\n");

    //// BLOCK - PARALLEL LINE
    now = Instant::now();
    let result_tp_block2: ResultStruct = mandel_tp_block_par_line(npoints, maxiter, block_size, nthreads);
    let end_tp_block2: std::time::Duration = now.elapsed();
    //println!("ThreadPool MandelBrot Block Done!\n");

    //// BLOCK - PARALLEL BLOCK
    now = Instant::now();
    let result_tp_block: ResultStruct = mandel_tp_block(npoints, maxiter, block_size, nthreads);
    let end_tp_block: std::time::Duration = now.elapsed();

    // RAYON
    now = Instant::now();
    let result_rayon: ResultStruct = mandel_rayon(npoints, maxiter);
    let end_rayon: std::time::Duration = now.elapsed();
    //println!("Rayon MandelBrot Done!\n");

    if result_seq.numoutside == result_for_seq.numoutside
        || result_seq.numoutside == result_tp_cell.numoutside
        || result_seq.numoutside == result_tp.numoutside
        || result_seq.numoutside == result_tp_block.numoutside
        || result_seq.numoutside == result_rayon.numoutside
    {

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

    println!(" ,Time (ms),Num Outside,Matrix Size,Block Size,Nr Threads\n");
    println!(
        "MandelBrot Area Calc, , ,{:?},{:?},{:?}\n",
        npoints,
        block_size,
        nthreads
    );
    println!(
        "Sequential,{:?},{:?}\n",
        end_seq.as_millis(),
        result_seq.numoutside,
    );
    println!(
        "Sequential (FOR),{:?},{:?}\n",
        end_for.as_millis(),
        result_for_seq.numoutside
    );
    println!(
        "ThreadPool Cell,{:?},{:?}\n",
        end_tp_cell.as_millis(),
        result_tp_cell.numoutside
    );
    println!(
        "ThreadPool Line,{:?},{:?}\n",
        end_tp_line.as_millis(),
        result_tp.numoutside
    );
    println!(
        "ThreadPool Block Parallel p/ Line,{:?},{:?}\n",
        end_tp_block2.as_millis(),
        result_tp_block2.numoutside
    );
    println!(
        "ThreadPool Block,{:?},{:?}\n",
        end_tp_block.as_millis(),
        result_tp_block.numoutside
    );
    println!(
        "Rayon,{:?},{:?}\n",
        end_rayon.as_millis(),
        result_rayon.numoutside
    );
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

fn mandel_tp_cell(npoints: i32, maxiter: i32, nthreads: usize) -> ResultStruct {
    //let n_workers: usize = thread::available_parallelism().unwrap().get();
    let n_jobs = npoints * npoints;
    let pool: ThreadPool = ThreadPool::new(nthreads);
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

fn mandel_tp_line(npoints: i32, maxiter: i32, nthreads: usize) -> ResultStruct {
    //let n_workers: usize = thread::available_parallelism().unwrap().get();
    let n_jobs = npoints;
    let pool: ThreadPool = ThreadPool::new(nthreads);
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

fn mandel_tp_block_par_line(npoints: i32, maxiter: i32, block_size: i32, nthreads: usize) -> ResultStruct {
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
            for i in i_start..(i_start + block_size) {
                let txc = tx.clone();
                pool.execute(move || {
                    let mut local_numoutside = 0;
                    for j in j_start..(j_start + block_size) {
                        local_numoutside += testpoint(i, j, maxiter, npoints);
                    }
                    txc.send(local_numoutside)
                        .expect("[ThreadPool MandelBrot Block] Error sending local_numoutside");
                });
            }
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

fn mandel_tp_block(npoints: i32, maxiter: i32, block_size: i32, nthreads: usize) -> ResultStruct {
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
