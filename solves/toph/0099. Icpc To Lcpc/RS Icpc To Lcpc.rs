use std::io;
fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<i32>().expect("NUMBER");
    println!(
        "{}",
        (if (n < 1582 && n % 4 == 0) || (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            "I can participate in LCPC"
        } else {
            "I have to travel back to the past"
        })
    );
}
