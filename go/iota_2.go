package main

import "fmt"

const (
	i = 1 << iota
	j = 3 << iota
	k
	l
)

func main()  {
	fmt.Println("i = ", i)	// i = 1 << 0
	fmt.Println("j = ", j)	// j = 3 << 1
	fmt.Println("k = ", k)	// k = 3 << 2
	fmt.Println("l = ", l)	// l = 3 << 3
}