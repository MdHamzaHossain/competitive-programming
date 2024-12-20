package main

import "fmt"

func main() {
	var i int
	fmt.Scanf("%d", &i)
	i -= 2
	var s string
	if i > 1 && i%2 == 0 {
		s = "YES"
	} else {
		s = "NO"
	}
	fmt.Printf("%s\n", (s))
}
