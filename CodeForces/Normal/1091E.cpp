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
int a[500002];
int cnt[500002];
int acnt[500002];
int dp[500002];

int coba(int val){
    if(dp[val] != -1) return dp[val];
    memcpy(acnt, cnt, 4*(n+1));
    acnt[val]++;
    ll lsum = 0;
    ll rsum = 0;
    int counter = 0;
    for(int i=1, j=n, k=n+1, l=0;i<=n;++i, --k){
        while(acnt[j] == 0) --j;
        acnt[j]--;
        lsum += j;
        k -= acnt[l++];
        rsum += k;
        rsum -= min(i, j);
        if(lsum - rsum <= 1LL*i*(i-1))
            counter++;
    }
    return dp[val] = counter;
}

int main(){
    memset(dp, -1, sizeof dp);
    memset(cnt, 0, sizeof cnt);
	scanf("%d", &n);
    ll sum  =0;
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        sum += a[i];
        cnt[a[i]]++;
    }
    vector<int> candidate;
    for(i=0;i<=n;++i)
        if((i&1) == (sum&1))
            candidate.pb(i);
    int st = -1, ed = -1;
    int middle = -1;
    // getting the peak position
    int l = -1, r = (int)candidate.size()-1;
    while(r - l > 1) {
        int mid = (l+r)/2;
        int res1 = coba(candidate[mid]);
        int res2 = coba(candidate[mid+1]);
        if(res1 < res2)
            l = mid;
        else
            r = mid;
    }
    middle = l+1;
    if(coba(candidate[middle]) < n)
        return puts("-1"), 0;
    // geting lowerbound
    l = 0, r = middle;
    while(l < r){
        int mid = (l+r)/2;
        if(coba(candidate[mid]) < n)
            l = mid+1;
        else
            r = mid;
    }
    st = r;
    // getting upperbound - 1
    l = middle, r = candidate.size()-1;
    while(l < r){
        int mid = (l+r+1)/2;
        if(coba(candidate[mid]) < n)
            r = mid-1;
        else
            l = mid;
    }
    ed = l;
    for(;st<=ed;++st)
        printf("%d ", candidate[st]);
    puts("");
	return 0;
}