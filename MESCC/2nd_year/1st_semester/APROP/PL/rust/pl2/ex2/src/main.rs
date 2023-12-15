use std::sync::mpsc::channel;
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

    // SEQUENTIAL
    //// ITERATORS
    let mut now: Instant = Instant::now();
    let result_seq: ResultStruct = seq_mandel(npoints, maxiter);
    let end_seq: std::time::Duration = now.elapsed();

    //// FOR LOOP
    now = Instant::now();
    let result_for_seq: ResultStruct = for_seq_mandel(npoints, maxiter);
    let end_for: std::time::Duration = now.elapsed();

    // THREADPOOL
    now = Instant::now();
    let result_tp_cell: ResultStruct = mandel_tp(npoints, maxiter);
    let end_tp_cell: std::time::Duration = now.elapsed();

    if result_seq.numoutside == result_for_seq.numoutside
        || result_seq.numoutside == result_tp_cell.numoutside
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
            "[ThreadPool] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
            result_tp_cell.area, result_tp_cell.error, result_tp_cell.numoutside
        );
    } else {
        println!("Sequential Result = {:?}\n", result_seq.numoutside);
        println!("Sequential FOR Result = {:?}\n", result_for_seq.numoutside);
        println!("ThreadPool Result = {:?}\n", result_tp_cell.numoutside);
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
        "ThreadPool MandelBrot = {:?} ms\n",
        end_tp_cell.as_millis()
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

fn mandel_tp(npoints: i32, maxiter: i32) -> ResultStruct {
    let n_workers: usize = thread::available_parallelism().unwrap().get();
    let n_jobs = npoints * npoints;
    let pool: ThreadPool = ThreadPool::new(n_workers);
    let (tx, rx) = channel();
    let mut numoutside: i32 = 0;

    // Iterating over a grid of points.
    for i in 0..npoints {
        for j in 0..npoints {
            let txc = tx.clone();
            pool.execute(move || {
                let local_numoutside = testpoint(i, j, maxiter, npoints);
                txc.send(local_numoutside).expect("Error");
            });
        }
    }
    numoutside = rx.iter().take(n_jobs as usize).fold(0, |a, b| a + b);

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
