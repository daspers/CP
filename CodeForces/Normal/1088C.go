package main

import (
	"fmt"
	"bufio"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func main(){
	defer writer.Flush()
	var n, i int
	var a [2004]int
	var ans []int
	scanf("%d\n", &n)
	for i=0;i<n;i++ {
		scanf("%d", &a[i])
		a[i] += 900000
	}
	ans = append(ans, 900000)
	for i=0;i<n-1;i++ {
		ans = append(ans, a[i]-i)
		a[i] %= a[i]-i
	}
	printf("%d\n1 %d 900000\n", n, n)
	for i=1;i<n;i++ {
		printf("2 %d %d\n", i, ans[i])
	}
}