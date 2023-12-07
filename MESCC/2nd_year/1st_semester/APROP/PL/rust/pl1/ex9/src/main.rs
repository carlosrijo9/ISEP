use std::time::Instant;
mod func;

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

    let now = Instant::now();
    let result_seq = seq_mandel(npoints, maxiter);
    let end = now.elapsed();

    let now2 = Instant::now();
    let result_for_seq = for_seq_mandel(npoints, maxiter);
    let end2 = now2.elapsed();

    println!(
        "[SEQ] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
        result_seq.area, result_seq.error, result_seq.numoutside
    );

    if result_seq.numoutside != result_for_seq.numoutside {
        panic!("Result NOK")
    }
    println!(
        "[FOR SEQ] Area of Mandelbrot set = {:?} +/- {:?} (outside: {:?}))\n",
        result_for_seq.area, result_for_seq.error, result_for_seq.numoutside
    );

    println!("\n- ==== Performance ==== -\n");
    println!("Sequential MandelBrot = {:?} ms\n", end.as_millis());
    println!("Sequential (FOR) MandelBrot = {:?} ms\n", end2.as_millis());
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
            numoutside += testpoint_for(i, j, maxiter, npoints);
        }
    }

    // Calculating the area and error of the Mandelbrot set.
    let area = 2.0 * 2.5 * 1.125 * (npoints * npoints - numoutside) as f64 / (npoints * npoints) as f64;
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

    let result = (0..maxiter).into_iter().find(|_| {
        let temp: f64 = z.r * z.r - z.i * z.i + c.r;
        z.i = z.r * z.i * 2.0 + c.i;
        z.r = temp;
        return z.r * z.r + z.i * z.i > 4.0;
    });
    match result {
        Some(_) => 1,
        None => 0,
    }
}

fn testpoint_for(i: i32, j: i32, maxiter: i32, npoints: i32) -> i32 {
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
