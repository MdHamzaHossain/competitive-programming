package main

import "fmt"

func main() {
	var T int
	fmt.Scanf("%d", &T)
	for T > 0 {
		T = T - 1
		var W, G float32
		//fmt.Println(W);
		//fmt.Println(G);
		fmt.Scanf("%f %f", &W, &G)
		fmt.Printf("%.4f\n", (W/2 - G/2))
	}
}
