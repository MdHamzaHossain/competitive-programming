fn main() {
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let n = line.trim().parse::<i32>().expect("NUMBER");
    line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let m = line.trim().parse::<i32>().expect("NUMBER");
    println!(
        "{}",
        if (n > m) {
            "Champion\nRunner up"
        } else {
            "Runner up\nChampion"
        }
    );
}
