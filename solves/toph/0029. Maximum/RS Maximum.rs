fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<i32>().expect("NUMBER");
    line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();

    let inputs: Vec<i32> = line
        .trim()
        .split_whitespace()
        .map(|e| e.parse().expect("Please type a number!"))
        .collect();
    let mut max = 0;
    for i in 0..inputs.len() {
        //println!("{}", inputs[i]);

        if inputs[i] > max {
            max = inputs[i];
        }
    }
    println!("{}", max);
}
