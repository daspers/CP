#include <bits/stdc++.h>

using namespace std;

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
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
const double pi = acos(-1);

const int maxlen = 200*200*200*20;
int n,i,j,k,t;
int len, vlen, slen;
char s[202], ss[202];
char m[201][202];
int dp[201][201][201];

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	scanf("%s", s);
	len = strlen(s);
	for(i=0;i<n;++i)
		scanf("%s", m[i]);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(m[i][j]=='R')
				goto out;
		}
	}
	out : 
	vlen = 0;
	pcc now = {i, j};
	int iter = 0;
	int ans = 0, st=0;
	while(1){
		bool ada = false;
		for(j=0;j<len;++j){
			if(s[j]=='>'){
				if(m[now.fi][now.se+1] != '#'){
					now.se++;
					ada = true;
					if(dp[now.fi][now.se][j] == -1)
						dp[now.fi][now.se][j] = ++iter;
					else{
						++iter;
						ans = iter - dp[now.fi][now.se][j];
						st = j+1;
						goto doom;
					}
				}
			}
			else if(s[j]=='<'){
				if(m[now.fi][now.se-1] != '#'){
					now.se--;
					ada = true;
					if(dp[now.fi][now.se][j] == -1)
						dp[now.fi][now.se][j] = ++iter;
					else{
						++iter;
						ans = iter - dp[now.fi][now.se][j];
						st = j+1;
						goto doom;
					}
				}
			}
			else if(s[j]=='v'){
				if(m[now.fi+1][now.se] != '#'){
					now.fi++;
					ada = true;
					if(dp[now.fi][now.se][j] == -1)
						dp[now.fi][now.se][j] = ++iter;
					else{
						++iter;
						ans = iter - dp[now.fi][now.se][j];
						st = j+1;
						goto doom;
					}
				}
			}
			else{
				if(m[now.fi-1][now.se] != '#'){
					now.fi--;
					ada = true;
					if(dp[now.fi][now.se][j] == -1)
						dp[now.fi][now.se][j] = ++iter;
					else{
						++iter;
						ans = iter - dp[now.fi][now.se][j];
						st = j+1;
						goto doom;
					}
				}
			}
		}
		if(!ada)
			return puts("1") & 0;
	}
	doom:
	vector<int> can;
	vector<short> pat;
	can.pb(1);
	for(i=2;i<=sqrt(ans);++i){
		if(ans%i==0){
			can.pb(i);
			if(ans/i!=i)
				can.pb(ans/i);
		}
	}
	for(i=0;i<ans;){
		for(j=0;j<len && i<ans;++j){
			if(s[(st+j)%len]=='>'){
				if(m[now.fi][now.se+1] != '#'){
					now.se++;
					pat.pb(now.fi*n+now.se);
					++i;
				}
			}
			else if(s[(st+j)%len]=='<'){
				if(m[now.fi][now.se-1] != '#'){
					now.se--;
					pat.pb(now.fi*n+now.se);
					++i;
				}
			}
			else if(s[(st+j)%len]=='v'){
				if(m[now.fi+1][now.se] != '#'){
					now.fi++;
					pat.pb(now.fi*n+now.se);
					++i;
				}
			}
			else{
				if(m[now.fi-1][now.se] != '#'){
					now.fi--;
					pat.pb(now.fi*n+now.se);
					++i;
				}
			}
		}
	}
	sort(can.begin(), can.end());
	for(i=0;i<can.size();++i){
		bool bisa = true;
		for(j=0;j<can[i];++j){
			if(pat[j] != pat[can[i]+j]){
				bisa = false;
				break;
			}
		}
		if(bisa)
			return printf("%d\n", can[i]) & 0;
	}
	printf("%d\n", ans);
	return 0;
}