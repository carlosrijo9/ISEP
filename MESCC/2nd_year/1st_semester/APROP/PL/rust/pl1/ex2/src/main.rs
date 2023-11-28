use rand::Rng;
mod func;
use num::complex::Complex;
use std::f64::consts::PI;

pub struct ComplexNumber {
    number: f32,
    c_number: f32,
}

fn main() {
    let num1 = ComplexNumber {
        number: rand::thread_rng().gen_range(1.0..=10.0),
        c_number: rand::thread_rng().gen_range(1.0..=10.0),
    };

    let num2 = ComplexNumber {
        number: rand::thread_rng().gen_range(1.0..=10.0),
        c_number: rand::thread_rng().gen_range(1.0..=10.0),
    };

    
    let sum_result = func::add_complex(&num1, &num2);

    println!("{:?}+i{:?} + {:?}+i{:?} = {:?}+i{:?}", num1.number,num1.c_number,num2.number,num2.c_number,sum_result.number, sum_result.c_number);
}


// c1*c2 = (a*c-b*d)+i(a*d+b*c1)
// c1/c2 = ((a*c+b*d)/(c.pow(2)+d.pow(2))) + i((b*c-a*d)/(c.pow(2)+d.pow(2)))
// |c1| = sqrt(a.pow(2) + b.pow(2));
