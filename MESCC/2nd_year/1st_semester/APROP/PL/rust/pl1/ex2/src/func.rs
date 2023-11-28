use crate::ComplexNumber;

pub fn add_complex(num1: &ComplexNumber, num2: &ComplexNumber) -> ComplexNumber {
    let sum_result_r: f32 = num1.number + num2.number;
    let sum_result_i: f32 = num1.c_number + num2.c_number;

    let result = ComplexNumber {
        number: sum_result_r,
        c_number: sum_result_i,
    };
    return result;
}

pub fn add_complex_assert(a: &ComplexNumber, b: &ComplexNumber) -> num::Complex<f32> {
    let complex_num1: num::Complex<f32> = num::complex::Complex::new(a.number, a.c_number); // Must use floats
    let complex_num2 = num::complex::Complex::new(b.number, b.c_number);

    let sum = complex_num1 + complex_num2;

    return sum;
}
