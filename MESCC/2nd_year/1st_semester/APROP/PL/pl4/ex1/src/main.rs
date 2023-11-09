use rand::Rng;
mod func;

fn main() {
    let mut a: Vec<i32> = vec![0; 15];
    for elem in 0..a.len() {
        a[elem] = rand::thread_rng().gen_range(1..=100);
    }

    a.sort();

    let max_result = func::max(&a);
    let min_result = func::min(&a);
    let average_num_result = func::average_result(&a);
    let middle_result = func::find_middle(&a);

    println!("Vector is {:?} with size {:?}", a, a.len());
    println!("max is {}", max_result);
    println!("min is {}", min_result);
    println!("average is {}", average_num_result);
    println!("median is {:?}", middle_result);
}
