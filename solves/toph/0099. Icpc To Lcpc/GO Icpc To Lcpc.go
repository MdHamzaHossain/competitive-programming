package main

import "fmt"

func main() {

	var n int
	fmt.Scanf("%d", &n)
	var s string
	if (n < 1582 && n%4 == 0) || (n%400 == 0 || (n%4 == 0 && n%100 != 0)) {
		s = "I can participate in LCPC"
	} else {
		s = "I have to travel back to the past"
	}
	fmt.Printf("%s\n", s)

}
