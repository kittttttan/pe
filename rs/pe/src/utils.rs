pub fn get_divisors(n: u64) -> Vec<u64> {
    let mut vec = Vec::new();
    if n < 2 {
        return vec;
    }

    let limit = ((n as f64).sqrt().floor() as u64) + 1;
    let mut m = n;
    while m & 1 == 0 {
        vec.push(2);
        m >>= 1;
    }
    if m == 1 {
        return vec;
    }

    let mut i = 3;
    while i < limit {
        if m % i == 0 {
            vec.push(i);
            m /= i;
            if m < i {
                break;
            }
        } else {
            i += 2;
        }
    }
    if m > 1 {
        vec.push(m);
    }

    return vec;
}
