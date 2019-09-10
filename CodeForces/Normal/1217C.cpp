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
char s[200004];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        n = strlen(s);
        int len = 0;
        int ans = 0;
        set<pii> ss;
        for(int i=0;i<=max(n-20, 0);++i){
            for(int j=i;j<min(i+20, n);++j){
                int curr = 0;
                for(int k=j;k<min(i+20, n);++k){
                    curr = curr * 2 + s[k] - '0';
                    if(curr > n) break;
                    // cerr<<curr<<" "<<k-j+1<<" "<<k-j+1+len<<endl;
                    if(j == i) {
                        if(curr >= k-j+1 && curr <= k-j+1+len){
                            ss.insert({j - (curr - (k-j+1)), k});
                            // cerr<<1<<" "<<j<<" "<<k<<" "<<len<<endl;
                            // ans++;
                        }
                    }
                    else {
                        if(curr == k-j+1){
                            ss.insert({j, k});
                            // cerr<<2<<" "<<j<<" "<<k<<endl;
                            // ans++;
                        }
                    }
                }
            }
            if(s[i] == '1') len = 0;
            else len++;
        }
        printf("%d\n", (int)ss.size());
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