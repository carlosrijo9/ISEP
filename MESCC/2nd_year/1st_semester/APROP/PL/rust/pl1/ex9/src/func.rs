// pub fn seq_mandel(NPOINTS:i32, MAXITER:i32) -> result_struct {
//     let mut numoutside = 0;
//     let mut area = 0.0;
//     let mut error = 0.0;
//     let eps = 1.0e-5;

//     for i in 0..NPOINTS {
//         for j in 0..NPOINTS {
//             let mut c = complex_struct {
//                 r: -2.0 + 2.5 * (i as f64) / (NPOINTS as f64) + eps,
//                 i: 1.125 * (j as f64) / (NPOINTS as f64) + eps,
//             };
//             func::testpoint(&mut c, MAXITER);
//         }
//     }

//     area = 2.0 * 2.5 * 1.125 * ((NPOINTS * NPOINTS - numoutside) as f64) / (NPOINTS * NPOINTS) as f64;
//     error = area / NPOINTS as f64;

//     let result = result_struct { area, error };
//     result
// }

// pub fn testpoint(c: complex_struct, MAXITER:i32) {
//     let mut numoutside = 0;
//     let mut z = c;
//     for iter in 0..MAXITER {
//         let temp = z.r * z.r - z.i * z.i + c.r;
//         z.i = z.r * z.i * 2.0 + c.i;
//         z.r = temp;
//         if z.r * z.r + z.i * z.i > 4.0 {
//             numoutside += 1;
//             break;
//         }
//     }
// }
