extern crate pe;

use std::num::ParseIntError;

pub fn solve(args: Vec<String>) -> Result<(), ParseIntError> {
    let argc = args.len();

    let mut n = 1000;
    let mut is_loop = false;
    if argc > 1 {
        let arg1 = &args[1];
        if arg1 == "-l" {
            is_loop = true;
            if argc > 2 {
                let arg2 = &args[2];
                n = arg2.parse()?;
            }
        } else {
            n = arg1.parse()?;
        }
    }

    if is_loop {
        println!("n = {} (with loop)", n);
        println!("{}", pe::pe1::with_loop(n));
    } else {
        println!("n = {}", n);
        println!("{}", pe::pe1::no_loop(n));
    }

    Ok(())
}
