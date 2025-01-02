fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
	
    let i = line.trim().parse::<i32>().expect("NUM");
	line = String::new();
     std::io::stdin().read_line(&mut line).unwrap();

    let inputs: Vec<i32> = line
        .trim()
        .split_whitespace()
        .map(|e| e.parse().expect("Please type a number!"))
        .collect();

    println!("{}", i-inputs[0]-inputs[1]-inputs[2]);
}
Downlo