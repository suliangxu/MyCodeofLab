package main

import "fmt"

type Books struct {
	title string
	author string
	subject string
	book_id int
}

func main()  {
	var Book1 Books
	var Book2 Books

	Book1.title = "Go"
	Book1.author = "www.runoob.com"
	Book1.subject = "Language"
	Book1.book_id = 6495407

	Book2.title = "Python"
	Book2.author = "www.runoob.com"
	Book2.subject = "Language"
	Book2.book_id = 649570

	printBook(Book1)
	printBook(Book2)
}

func printBook(book Books)  {
	fmt.Printf( "Book title : %s\n", book.title)
	fmt.Printf( "Book author : %s\n", book.author)
	fmt.Printf( "Book subject : %s\n", book.subject)
	fmt.Printf( "Book book_id : %d\n", book.book_id)
}