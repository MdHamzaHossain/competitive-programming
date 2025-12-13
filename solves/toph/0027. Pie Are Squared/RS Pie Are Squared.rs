fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let inputs: Vec<f32> = line
        .trim()
        .split_whitespace()
        .map(|e| e.parse().expect("Please type a number!"))
        .collect();
    let mut res: f32 = inputs[0] * inputs[0] * 3.141592653589793;

    println!("{}", res);
}
