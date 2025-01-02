package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)

	var max int
	var a int
	fmt.Scanf("%d", &max)
	n--
	for n > 0 {
		n--
		fmt.Scanf("%d", &a)
		if a > max {
			max = a
		}
	}
	fmt.Printf("%d", max)
}
