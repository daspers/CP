package main

import (
	"fmt"
	"sort"
	"bufio"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func main(){
	defer writer.Flush()
	var a[100005]int
	var n,k,i int
	scanf("%d %d\n", &n, &k)
	a[0] = 0
	for i=1;i<=n;i++ {
		scanf("%d", &a[i])
	}
	sort.Ints(a[:n+1])
	for i=1;i<=n&&k>0;i++ {
		if(a[i] > a[i-1]){
			printf("%d\n", a[i] - a[i-1])
			k--;
		}
	}
	for k > 0 {
		printf("0\n")
		k--;
	}
}