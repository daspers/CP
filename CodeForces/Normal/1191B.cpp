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
map<char, int> d;
map<int, int> cnt[3];

int main(){
    d['m'] = 0;
    d['p'] = 1;
    d['s'] = 2;
    string a,b,c;
    cin>>a>>b>>c;
    cnt[d[a[1]]][a[0]-'0']++;
    cnt[d[b[1]]][b[0]-'0']++;
    cnt[d[c[1]]][c[0]-'0']++;
    int ans = 2;
    for(int i=0;i<3;++i){
        for(pii x : cnt[i]){
            ans = min(ans, 3-x.se);
        }
        for(int j=1;j<9;++j){
            if((j<8 && cnt[i][j] > 0 && cnt[i][j+1] > 0 && cnt[i][j+2] > 0)) ans=0;
            if((cnt[i][j] > 0 && cnt[i][j+1] > 0) || (j<8 && cnt[i][j] > 0 && cnt[i][j+2] > 0)){
                ans = min (ans, 1);
            }
        }
    }
    printf("%d\n", ans);
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