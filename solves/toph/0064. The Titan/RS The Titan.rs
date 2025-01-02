fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();

    let mut i = line.trim().parse::<i32>().expect("NUM");
    let mut sum = 0;
    i = i + 1;
    while i > 0 {
        i = i - 1;
        sum = sum + i * i;
    }
    println!("{}", sum);
}
