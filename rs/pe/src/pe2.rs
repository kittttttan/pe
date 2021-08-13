/// # Solve project euler 2
///
/// By considering the terms in the Fibonacci sequence
/// whose values do not exceed four million,
/// find the sum of the even-valued terms.

pub fn calc(n: u32) -> u32 {
    let (mut a, mut b, mut s) = (1, 2, 2);

    while b <= n {
        // (a, b) = (b, a + b);
        let t = a;
        a = b;
        b = t + b;

        if b & 1 == 0 {
            s += b;
        }
    }

    return s;
}

pub fn pe2() {
    let s: u32 = calc(4000000);
    println!("{}", s);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let cases: [u32; 3] = [
            10, 100, 4000000,
        ];
        let expects: [u32; 3] = [
            10, 188, 4613732,
        ];
        for i in 0..3 {
            let case = cases[i as usize];
            let expect = expects[i as usize];
            assert_eq!(calc(case), expect);
        }
    }
}
