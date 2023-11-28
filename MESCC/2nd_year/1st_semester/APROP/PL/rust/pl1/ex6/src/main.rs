mod func;

fn main() {
    let min = 1;
    let max = 100;
    let upper_bound = 10;

    // a)
    let result: i32 = func::add_all_integer(min, max);
    println!("Sum {:?} to {:?} -> result = {:?}", min, max, result);

    func::add_square(min, max, upper_bound);

    // b)
    let result_square = func::add_square(min, max, upper_bound);
    println!("Upper bound = {:?} -> result = {:?}", upper_bound, result_square);
}
