fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let i: i32 = line.trim().parse::<i32>().expect("NUMBER");
    println!("{}", i * i);
}
