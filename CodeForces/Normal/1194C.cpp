#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void printArray(const int *arr, int n);
void printArray(const vector<int> &arr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
char a[200];
char b[200];
char c[200];
int la, lb, lc;
int cnta[30];
int cntb[30];
int cntc[30];

int main(){
	scanf("%d", &t);
    while(t--){
        memset(cnta, 0, sizeof cnta);
        memset(cntb, 0, sizeof cntb);
        memset(cntc, 0, sizeof cntc);
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", c);
        la = strlen(a);
        lb = strlen(b);
        lc = strlen(c);
        for(int i=0;i<lb;++i){
            cntb[b[i]-'a']++;
        }
        for(int i=0;i<la;++i){
            cnta[a[i]-'a']++;
        }
        for(int i=0;i<lc;++i){
            cntc[c[i]-'a']++;
        }
        bool bisa = true;
        for(int i=0;i<26;++i){
            if(cnta[i] > cntb[i] || cnta[i] + cntc[i] < cntb[i] ){
                bisa = false;
            }
        }
        if(bisa){
            for(i=0,j=0;i<la && j<lb;++j){
                if(a[i] == b[j]){
                    ++i;
                }
            }
            puts(i<la? "NO" : "YES");
        }
        else puts("NO");
    }
	return 0;
}

/* Template Function */
void printArray(const int * a, int n){
	for(int i=0;i<n;++i){
		printf("%d ", a[i]);
	}
	puts("");
}

void printArray(const vector<int> &arr){
	for(int x : arr){
		printf("%d ", x);
	}
	puts("");
}