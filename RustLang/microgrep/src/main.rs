use std::{env, process};

use microgrep::Config;

fn main() {
    let config = Config::build(env::args()).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {err}");
        process::exit(1);
    });

    println!("Searching for {}\nIn file {}", config.query, config.file_path);

    if let Err(e) = microgrep::run(config) {
        eprintln!("Application error: {e}");
        process::exit(1);
    }
}