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

func abs(val int) int {
	if (val < 0) {
		return -val
	}
	return val
}

func min(a,b int) int {
	if (a < b) {
		return a
	}
	return b
}

func main(){
	defer writer.Flush()
	var t,n,d,x,y, ans int
	scanf("%d\n", &t)
	for t > 0 {
		scanf("%d %d %d %d\n", &n, &x, &y, &d)
		if (abs(x-y) % d == 0) {
			printf("%d\n", abs(x-y) / d)
		} else {
			ans = -1
			if ((y-1) % d == 0) {
				ans = (y-1)/d + (x-1 + d-1)/d
			}
			if ((n-y) % d == 0) {
				if (ans == -1){
					ans = (n-y)/d + (n-x + d-1)/d
				} else {
					ans = min(ans, (n-y)/d + (n-x + d-1)/d)
				}
			}
			printf("%d\n", ans)
		}
		t--
	}
}