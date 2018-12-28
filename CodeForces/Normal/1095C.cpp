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

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;

int main(){
	scanf("%d %d", &n, &k);
    // cout<<"wtf"<<endl<<flush;
    priority_queue<int> pq;
    for(i=0;n;++i){
        if(n & 1)
            pq.push(1<<i);
        n >>= 1;
    }
    if(k < pq.size()){
        return puts("NO"), 0;
    }
    while(pq.size() < k && pq.top() != 1){
        int tmp = pq.top()/2;
        pq.pop();
        pq.push(tmp);
        pq.push(tmp);
    }
    if(pq.size() < k)
        return puts("NO"), 0;
    puts("YES");
    while(!pq.empty()){
        printf("%d ", pq.top());
        pq.pop();
    }
    puts("");
	return 0;
}