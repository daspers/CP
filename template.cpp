#include <bits/stdc++.h>

#define itt(i,a) for(auto i=a.begin();i!=a.end();++i)
#define rep(i,a) for(i=0;i<a;i++)
#define brep(i,a) for(i=a-1;i>=0;i--)
#define rrep(i,a) for(i=1;i<=a;i++)
#define srep(i,a,b) for(i=a;i<b;i++)
#define V(T) vector<T>
#define VV(T) vector<vector<T>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define set(m,s) memset(m, s, sizeof(m));
#define sz(x) (x).size()
#define ins insert
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
const int N = 10000;
const long NL = 1e6+5;
const long mod = 1e8+7;
const double eps = 1e-10;

using namespace std;

void readi(int &number);
void readll(ll &number);
void readull(ull &number);

int t,i,j,k, x;

int main(){
	readi(t);
	printf("%d\n", t);
	// rep(i,t){
		// readi(x);
		// printf("%d\n", x);
	// }
	return 0;
}

void readi(int &number){
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number = ~number+1;
}

void readi(ll &number){
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number = ~number+1;
}

void readull(ull &number){
    register int c;
    number = 0;
    c = getchar();
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
