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
func flush(){ writer.Flush() }

func main(){
	var ans [100]int
	var a,b,val,i int
	a = 0
	b = 0
	fmt.Printf("? 0 0\n");
	fmt.Scanf("%d\n", &ans[0])
	val = 1<<29
	for i=1;i<=30;i++ {
		fmt.Printf("? %d %d\n", val|a, b)
		fmt.Scanf("%d\n", &ans[2*i-1])
		fmt.Printf("? %d %d\n", a, val|b)
		fmt.Scanf("%d\n", &ans[2*i])
		if (ans[2*i-1] == 1 && ans[2*i] == -1){

		} else if (ans[2*i-1]==-1 && ans[2*i]==1){
			a |= val
			b |= val
		} else if (ans[2*i-1] == ans[2*i]){
			if(ans[0] == 1) {
				a |= val;
			} else {
				b |= val;
			}
			ans[0] = ans[2*i];
		}
		val >>= 1
	}
	fmt.Printf("! %d %d\n", a, b)
}