package main

import "fmt"

func main() {
	var y int
	fmt.Scanf("%d", &y)
	if ((y%4 == 0) && (y%100 != 0)) || (y%400 == 0) {
		fmt.Printf("Yes\n")
	} else {
		fmt.Printf("No\n")
	}
}
