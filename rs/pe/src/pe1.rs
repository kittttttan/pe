/// # Solve project euler 1
///
/// Add all the natural numbers below one thousand
/// that are multiples of 3 or 5.

pub fn with_loop(n: u32) -> u32 {
    let mut s: u32 = 0;
    for i in 1..n + 1 {
        if i % 3 == 0 || i % 5 == 0 {
            s += i;
        }
    }
    return s;
}

pub fn no_loop(n: u32) -> u32 {
    let mut s: u32 = 0;
    if n > 2 {
        let n3: u32 = n / 3;
        let n5: u32 = n / 5;
        let n15: u32 = n / 15;
        s = (3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) >> 1;
    }
    return s;
}

pub fn pe1() {
    let s: u32 = with_loop(1000);
    println!("{}", s);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let cases: [u32; 5] = [
            0, 10, 100, 1000, 10000,
        ];
        let expects: [u32; 5] = [
            0, 33, 2418, 234168, 23341668,
        ];
        for i in 0..5 {
            let case = cases[i as usize];
            let expect = expects[i as usize];
            assert_eq!(with_loop(case), expect);
            assert_eq!(no_loop(case), expect);
        }
    }
}
