extern crate pe_cli;

use pe_cli::pe1;
use std::env;
use std::num::ParseIntError;

fn main() -> Result<(), ParseIntError> {
    let args: Vec<String> = env::args().collect();
    let argc = args.len();
    if argc < 2 {
        println!("required problem number");
        return Ok(());
    }

    let n = args[1].parse()?;
    println!("problem {}", n);
    match n {
        1 => pe1::solve((&args[1..]).to_vec()),
        _ => {
            println!("not implemented");
            Ok(())
        },
    }
}
