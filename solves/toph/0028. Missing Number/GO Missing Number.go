package main

import "fmt"

func main() {
	var t int
	fmt.Scanf("%d", &t)
	var a int
	var b int
	var c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	fmt.Printf("%d", t-a-b-c)
}
