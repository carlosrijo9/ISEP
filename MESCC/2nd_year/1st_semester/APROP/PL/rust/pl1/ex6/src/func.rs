pub fn add_all_integer(min_val: i32, max_val: i32) -> i32 {
    let sum: i32 = (min_val..=max_val).into_iter().sum();

    return sum;
}

pub fn add_square(min_val: i32, max_val: i32, limit_val: i32) -> i32 {
    let sum_square = (min_val..max_val)
        .into_iter()
        .filter(|&elem| elem < limit_val)
        .reduce(|acc: i32, elem: i32| acc + elem.pow(2))
        .unwrap_or(0);

    return sum_square;
}
