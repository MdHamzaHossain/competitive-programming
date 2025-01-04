package main

import "fmt"

func main() {
	var n int
	var m int
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d", &m)
	var s string
	if n > m {
		s = "Champion\nRunner up\n"
	} else {
		s = "Runner up\nChampion\n"
	}
	fmt.Print(s)
}
