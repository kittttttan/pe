/// # Solve project euler 1
///
/// Add all the natural numbers below one thousand
/// that are multiples of 3 or 5.

fn pe1a(n: u32) -> u32 {
    let mut s: u32 = 0;
    for i in 1..n + 1 {
        if i % 3 == 0 || i % 5 == 0 {
            s += i;
        }
    }
    return s;
}

fn pe1b(n: u32) -> u32 {
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
    let s: u32 = pe1a(1000);
    println!("{}", s);
}
