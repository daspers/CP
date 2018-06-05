#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n, i,j,k,t;
int a, m;
ll dp[2002][2002];
int b[2002];
int w[2002];
int mep[2002];

ll solve(int co, int umb){
	ll &ans = dp[co][umb];
	if(ans == -1){
		if(co == a){
			ans = 0;
		}
		else{
			if(mep[co]){ // raining
				if(umb){ // use umbrella
					if(w[co] && w[co]<w[b[umb]]){ // there is umbrella and minimum
						int lb = lower_bound(b+1, b+m+1, co) - b;
						ans = w[co] + solve(co+1, lb);
					}
					else{
						ans = w[b[umb]] + solve(co+1, umb);
					}
				}
				else{ // not using umbrella
					if(w[co]){ // there is umbrella
						int lb = lower_bound(b+1, b+m+1, co) - b;
						ans = w[co] + solve(co+1, lb);
					}
					else // no umbrella
						ans = INF;
				}
			}
			else{ // it's not raining
				if(umb){ // use umbrella
					ans = min(w[b[umb]] + solve(co+1, umb), solve(co+1, 0));
					if(w[co] && w[co]<w[b[umb]]){
						int lb = lower_bound(b+1, b+m+1, co) - b;
						ans = min(ans, w[co] + solve(co+1, lb));
					}
				}
				else{ // not using umbrella
					ans = solve(co+1, 0);
					if(w[co]){ // there is umbrella
						int lb = lower_bound(b+1, b+m+1, co) - b;
						ans = min(ans, w[co] + solve(co+1, lb));
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	memset(w, 0, sizeof w);
	memset(mep, 0, sizeof mep);
	scanf("%d %d %d", &a, &n, &m);
	for(i=0;i<n;++i){
		int l, r;
		scanf("%d %d", &l, &r);
		mep[l]++;
		mep[r]--;
	}
	for(i=1;i<=m;++i){
		scanf("%d", b+i);
		scanf("%d", w+b[i]);
	}
	for(i=1;i<=a;++i)
		mep[i] += mep[i-1];
	sort(b+1, b+m+1);
	ll ans = solve(0,0);
	printf("%lld\n", (ans<0||ans>=INF?-1:ans));
	return 0;
}
