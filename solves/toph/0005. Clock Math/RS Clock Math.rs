fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let inputs: Vec<i32> = line
        .trim()
        .split_whitespace()
        .map(|e| e.parse().expect("Please type a number!"))
        .collect();
    let H = inputs[0];
    let M = inputs[1];
    let mut angle: f32 = ((60 * H - 11 * M) as f32) / 2.00;

    if angle > 180.0 {
        angle = 360.000 - angle;
    }
    println!("{}", angle);
}
