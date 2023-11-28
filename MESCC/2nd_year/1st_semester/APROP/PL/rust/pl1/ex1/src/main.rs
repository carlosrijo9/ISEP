use rand::Rng;
mod func;

fn main() {
    let mut a: Vec<i32> = vec![0; 15];
    let mut b: Vec<i32> = vec![0; 15];
    let mut c: Vec<i32> = vec![0; 15];

    let a_size = a.len();
    let b_size = b.len();
    let c_size = c.len();

    // Fill vector a
    for elem in 0..a.len() {
        a[elem] = rand::thread_rng().gen_range(1..=100);
    }

    // Fill vector b
    for elem in 0..b.len() {
        b[elem] = rand::thread_rng().gen_range(1..=100);
    }

    //1a)
    let max_result = func::max(&a);
    let min_result = func::min(&a);
    let average_num_result = func::average_result(&a);

    //1d)
    // func::quick_sort_vector(&mut a, 0, a_size - 1);
    // func::quick_sort_vector(&mut b, 0, b_size - 1);
    // func::quick_sort_vector(&mut c, 0, c_size - 1);

    //1e)
    println!("Vector a is {:?} with size {:?}", a, a.len());
    func::bubble_sort(&mut a, a_size);
    println!("Vector a is {:?} with size {:?}", a, a.len());
    //1b)
    let middle_result = func::find_middle(&a);

    //1c)
    c = func::sum_vector(&a, &b);

    //1e)
    func::bubble_sort(&mut a, a_size);

    //1f)

    println!("Vector a is {:?} with size {:?}", a, a.len());
    println!("Vector b is {:?} with size {:?}", b, b.len());
    println!("Vector c is {:?} with size {:?}", c, c.len());
    println!("max is {}", max_result);
    println!("min is {}", min_result);
    println!("average is {}", average_num_result);
    println!("median is {:?}", middle_result);
}
