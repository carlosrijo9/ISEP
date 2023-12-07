// pub fn testpoint(i: i32, j: i32, maxiter: i32, npoints: i32) -> i32 {
//     let eps = 1.0e-5;

//     let c: ComplexStruct = ComplexStruct {
//         r: -2.0 + 2.5 * (i as f64) / (npoints as f64) + eps,
//         i: 1.125 * (j as f64) / (npoints as f64) + eps,
//     };

//     let mut z: ComplexStruct = c.clone();

//     let result = (0..maxiter).into_iter().find(|_| {
//         let temp: f64 = z.r * z.r - z.i * z.i + c.r;
//         z.i = z.r * z.i * 2.0 + c.i;
//         z.r = temp;
//         return z.r * z.r + z.i * z.i > 4.0;
//     });
//     match result {
//         Some(_) => 1,
//         None => 0,
//     }
// }
