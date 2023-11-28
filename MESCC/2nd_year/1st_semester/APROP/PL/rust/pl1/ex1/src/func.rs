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
            panic!("vector not sorted")
        }
    }
    let odd = a.len() as f32 % 2.0;
    let med = a.len() / 2;
    if odd == 0.0 {
        middle_num = ((a[med] + a[med + 1]) as f32) / 2.0;
    } else {
        middle_num = a[med] as f32;
    }

    return middle_num as f32;
}

pub fn sum_vector(a: &Vec<i32>, b: &Vec<i32>) -> Vec<i32> {
    let mut result: Vec<i32> = vec![0; a.len()];

    for (index, element) in a.iter().enumerate() {
        result[index] = &a[index] + &b[index];
    }

    return result;
}

pub fn quick_sort_vector(vector: &mut Vec<i32>, low: usize, high: usize) {
    /* The main process of the function */
    if low < high {
        let mut m_split;

        /* Specify the middle of the vector by calling the split function */
        m_split = split_vect(vector, low, high);

        /* Call the quick_sort function to sort the antecedent vector */
        if m_split != 0 {
            quick_sort_vector(vector, low, m_split - 1);
        }
        /* Call the quick_sort function to sort the subsequent vector */
        quick_sort_vector(vector, m_split + 1, high);
    }

    //return vector;
}

pub fn split_vect(mut vector: &mut Vec<i32>, low: usize, high: usize) -> usize {
    let index = vector[high];
    let mut m = low as i32 - 1;

    for i in low..=high - 1 {
        if vector[i] < index {
            m += 1;
            vector.swap(m as usize, i);
            //swap_element(&mut vector[m as usize], &mut vector[i]);
        }
    }

    vector.swap((m + 1) as usize, high);
    //swap_element(&mut vector[(m + 1) as usize], &mut vector[high]);
    (m + 1) as usize
}

pub fn bubble_sort(vector: &mut Vec<i32>, size: usize) {
    let mut swapped:bool = true;

    // Loop until no more swaps are needed.
    while swapped == true {
        
        swapped = false;

        // Iterate through the array, comparing adjacent elements.
        for i in 0..size - 1 {
            // Swap elements if they are out of order.
            if vector[i] > vector[i + 1] {
                vector.swap(i, i + 1);
                swapped = true;
            }
        }

        // If no swaps were made during the iteration, the array is sorted.
        if !swapped {
            break;
        }
    }
}
