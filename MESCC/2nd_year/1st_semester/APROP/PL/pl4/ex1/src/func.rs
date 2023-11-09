pub fn max(a: &Vec<i32>) -> i32 {
    let mut big_num = std::i32::MIN;

    for elem in a {
        if *elem > big_num {
            big_num = *elem;
        }
    }
    return big_num;
}

pub fn min(a: &Vec<i32>) -> i32 {
    let mut small_num = std::i32::MAX;

    for elem in a {
        if *elem < small_num {
            small_num = *elem;
        }
    }
    return small_num;
}

pub fn average_result(a: &Vec<i32>) -> f32 {
    let mut av_num: i32 = 0;

    for elem in a {
        av_num += elem;
    }

    let average_num = av_num as f32 / a.len() as f32;

    return average_num;
}

pub fn find_middle(a: &Vec<i32>) -> f32 {
    let mut middle_num: f32 = 0.0;

    for i in 1..a.len() {
        if a[i - 1] > a[i] {
            panic!("array not sorted")
        }
    }
    let odd = a.len() as f32 % 2.0;
    let med = a.len() / 2;
    if odd == 0.0 {
        middle_num = ((a[med] + a[med + 1]) as f32) / 2.0;
    } 
    else {
        middle_num = a[med] as f32;
    }

    return middle_num as f32;
}