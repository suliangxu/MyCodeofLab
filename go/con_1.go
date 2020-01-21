// 常量中的数据类型只可以是布尔型、数字型（整数型、浮点型和复数）和字符串型。

package main

import "fmt"

func main()  {
	const LENGTH int = 10
	const WIDTH int = 5
	var area int
	const a, b, c = 1, false, "str"

	area = LENGTH * WIDTH
	fmt.Printf("面积为： %d", area)
	println()
	println(a, b, c)
}