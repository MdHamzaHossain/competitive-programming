fn main() {
    let mut line = String::new();
    let b1 = std::io::stdin().read_line(&mut line).unwrap();
    let A = line.trim().parse().expect("Number");
    for i in 1..=A {
        if A % i == 0 {
            println!("{}", i);
        }
    }
}
