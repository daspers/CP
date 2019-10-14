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
bool bisa[202], vis[203];
int a[202];

void coba(int a, int b){
    for(int i=0;i<min(a, b);++i){
        if(a + b - 1 > 2*n-1) continue;
        bisa[a+b-2*i] = true;
    }
}

int main(){
	scanf("%d", &n);
    int ans = 0;
    for(int i=0;i<2*n-1;++i){
        scanf("%d", a+i);
        ans += a[i];
    }
    sort(a, a+2*n-1);
    int cntn = 0, cntz = 0;
    for(int i=0;i<2*n-1;++i){
        cntn+= a[i]<0;
        cntz+= a[i]==0;
    }
    bisa[0] = true;
    priority_queue<int> pq;
    pq.push(n);
    while(!pq.empty()){
        int val = pq.top();
        pq.pop();
        for(int i=0;i<min(val, n);++i){
            if(val + n - 1 > 2*n-1) continue;
            if(!vis[val+n-2*i]) pq.push(val+n-2*i);
            vis[val+n-2*i] = true;
            bisa[val+n-2*i] = true;
        }
    }
    for(int i=0;i<=2*n-1;++i){
        if(bisa[i]){
            int tmp = 0;
            for(int j=0;j<=2*n-1;++j){
                tmp += j < i ? -a[j] : a[j];
            }
            ans = max(ans, tmp);
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