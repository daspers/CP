package main

import (
	"fmt"
)

func main(){
	var x int32
	fmt.Scanf("%d", &x)
	if(x == 1){
		fmt.Println(-1)
	}else{
		fmt.Println(x, x)
	}
}