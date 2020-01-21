package main

// 声明全局变量
//但是全局变量是允许声明但不使用，局部变量不允许不使用
var x, y int
var(
	a int
	b bool
)

var c, d int =1, 2
var e, f = 123, "hello"

func main()  {
	g, h := 123, "hello"
	println(x, y, a, b, c, d, e, f, g, h)
}
