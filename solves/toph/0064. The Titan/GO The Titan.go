package main

import "fmt"

func main() {
	var a int
	fmt.Scanf("%d", &a)
	a++
	var sum int
	sum = 0
	for a > 0 {
		a--
		sum += a * a
	}
	fmt.Printf("%d", sum)
}
