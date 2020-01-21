package main

import "fmt"

type Books struct {
	title string
	author string
	subject string
	book_id int
}

func main()  {
	fmt.Println(Books{"Go", "www.runoob.com", "Language", 6495407})

	fmt.Println(Books{title:"Go", author:"www.runoob.com", subject:"Language", book_id:6495407})

	fmt.Println(Books{title:"Go", author:"www.runoob.com"})
}