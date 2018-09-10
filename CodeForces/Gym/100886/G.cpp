#include <bits/stdc++.h>

using namespace std;

#pragma GCC push_options
#pragma GCC optimize("O2")

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-8
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,i,j,k,t;
ll dp[20][2][2];
bool zero[20];
string a, b;

ll solve(int idx, bool ba, bool bb){
	ll &ans = dp[idx][ba][bb];
	if(ans == -1){
		if(ba){
			// cout<<"call "<<idx<<" : "<<a[idx]-'0'<<endl;
			ans = max(ans, (a[idx]-'0')*solve(idx+1, true, bb && a[idx] == b[idx]));
		}
		if(bb){
			// cout<<"call "<<idx<<" : "<<a[idx]-'0'<<endl;
			if(b[idx] == '0' && !zero[idx])
				ans = max(ans, solve(idx+1, ba && a[idx] == b[idx], true));
			else
				ans = max(ans, (b[idx]-'0')*solve(idx+1, ba && a[idx] == b[idx], true));
		}
		int awal = bb ? b[idx]-'0'+1 : 1;
		int akhir = ba ? a[idx] -'1' : 9;
		for(;awal<=akhir;++awal){
			ans = max(ans, awal*solve(idx+1, false, false));
		}
	}
	return ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	cin>>b>>a;
	while(b.size() < a.size())
		b = "0"+b;
	dp[a.size()][0][0] = dp[a.size()][1][1] = dp[a.size()][1][0] = dp[a.size()][0][1] = 1;
	memset(zero, true, sizeof zero);
	for(i=0;i<a.size();++i){
		if(b[i] > '0')
			break;
		zero[i] = false;
	}
	ll tmp = solve(0, true, true);
	int sa = 1, sb = 1;
	bool printed = false;
	string ans ="";
	for(i=0;i<a.size();++i){
		if(sa && dp[i+1][sa][sb && b[i] == a[i]]>=0){
			if(dp[i][sa][sb]==0){
				ans += a[i];
				sb = sb && b[i]==a[i];
				continue;
			}
			else if(dp[i+1][sa][sb && b[i] == a[i]]>0){
				ll tmp = dp[i][sa][sb]/dp[i+1][sa][sb && b[i] == a[i]];
				if(dp[i][sa][sb]%dp[i+1][sa][sb && b[i] == a[i]] == 0 && tmp <= 9 && tmp == a[i]-'0'){
					ans += a[i];
					sb = sb && b[i]==a[i];
					continue;
				}
			}
		}
		if(sb && dp[i+1][sa && a[i]==b[i]][sb]>0 ){
			ll tmp = dp[i][sa][sb]/dp[i+1][sa && a[i]==b[i]][sb];
			if(dp[i][sa][sb]%dp[i+1][sa && a[i]==b[i]][sb] == 0 &&  tmp<=9){
				if(b[i]=='0'){
					if(dp[i+1][sa && a[i]==b[i]][sb] == dp[i][sa][sb]){
						ans += b[i];
						sa = sa && b[i]==a[i];
						continue;
					}
				}
				else if(tmp == b[i]-'0'){
					ans += b[i];
					sa = sa && b[i]==a[i];
					continue;
				}
			}
		}
		if(dp[i+1][0][0]>0 && dp[i][sa][sb] % dp[i+1][0][0]==0 && dp[i][sa][sb]/dp[i+1][0][0] <= 9){
			ans += (dp[i][sa][sb]/dp[i+1][0][0])+'0';
			sa = sb = 0;
		}
	}
	while(ans.size() > 1 && *ans.begin() == '0')
		ans.erase(ans.begin());
	cout<<ans<<"\n";
	return 0;
}