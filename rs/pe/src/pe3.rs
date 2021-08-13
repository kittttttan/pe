/// # Solve project euler 3
///
/// Find the largest prime factor of a composite number.
use utils::get_divisors;

pub fn calc(n: u64) -> Vec<u64> {
    return get_divisors(n);
}

pub fn pe3() {
    let s: Vec<u64> = calc(600851475143);
    println!("{:?}", s);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let ps = calc(600851475143);
        assert_eq!(ps, [71, 839, 1471, 6857]);
    }
}
