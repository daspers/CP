#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,x,y;
char c;

int main(){
	while(scanf("%c", &c)==1){
		if(c>='0'&&c<='9'){
			switch(c){
				case '0' :
					printf("o");
					break;
				case '1' :
					printf("i");
					break;
				case '2' :
					printf("r");
					break;
				case '3' :
					printf("e");
					break;
				case '4' :
					printf("a");
					break;
				case '5' :
					printf("s");
					break;
				case '6' :
					printf("b");
					break;
				case '7' :
					printf("t");
					break;
				case '8' :
					printf("%c", c);
					break;
				case '9' :
					printf("g");
					break;
			}
		}
		else
			printf("%c", c);
	}
	return 0;
}
