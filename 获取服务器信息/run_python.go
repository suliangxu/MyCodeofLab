package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
	"time"
)

func main() {
	GlobalLimit := make(chan string, 1)

	// 创建文件
	filePath := "result.txt"
	file, err := os.OpenFile(filePath, os.O_WRONLY | os.O_CREATE, 0666)
	if err != nil {
		fmt.Printf("open file err=%v\n", err)
		return
	}
	//及时关闭file句柄
	defer file.Close()

	writer := bufio.NewWriter(file)

	for {
		GlobalLimit <- "s"
		time.AfterFunc(30*time.Minute, func() {
			//fmt.Println("1")
			//写你的业务逻辑
			cmd := exec.Command("python",  "Read_info.py")
			//cmd := exec.Command("pwd")
			out, err := cmd.Output()
			if err != nil {
				fmt.Println(err)
			}
			writer.WriteString(time.Now().String())
			writer.WriteString("\n")
			writer.WriteString(string(out))
			writer.Flush()
			fmt.Println(time.Now().String())
			fmt.Println(string(out))

			<-GlobalLimit
		})

	}
}