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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main(){
	defer writer.Flush()
	var n,l,r,ans,cnt,m,i int
	var a, b []int
	var s string
	scanf("%d\n", &n)
	scanf("%s\n", &s)
	// printf("read : %s\n", s)
	cnt = 0
	for i=0;i<n;i++ {
		if s[i] == 'G' {
			cnt++
		}
	}
	m=0
	l=0
	r=0
	for l < n {
		if l == r {
			r++
		} else if r < n && s[r] == 'G' {
			r++
		} else if s[l] != 'G' {
			l++
		} else {
			m++
			a = append(a, l)
			b = append(b, r)
			// printf("add %d %d\n", l, r)
			l = r
		}
	}
	ans = 0
	for i=0;i<m;i++ {
		ans = max(ans, b[i]-a[i])
		if m > 1 {
			ans = max(ans, b[i]-a[i]+1)
		}
	}
	for i=1;i<m;i++ {
		if a[i] - b[i-1] == 1 {
			ans = max(ans, b[i]-a[i] + b[i-1] - a[i-1])
			if m > 2 {
				ans = max(ans, b[i]-a[i] + b[i-1] - a[i-1] + 1)
			}
		}
	}
	printf("%d\n", ans)
}