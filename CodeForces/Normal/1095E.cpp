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
int l[1000002];
int r[1000002];
bool vall[1000002];
bool valr[1000002];
char s[1000002];

int main(){
    scanf("%d", &n);
    scanf("%s", s+1);
    stack<pair<char, int> > st;
    l[0] = 0;
    vall[0] = true;
    for(i=1;i<=n;++i){
        l[i] = l[i-1];
        vall[i] = vall[i-1];
        if(s[i] == '('){
            l[i]++;
        }
        else{
            l[i] --;
            if(l[i] < 0)
                vall[i] = false;
        }
    }
    r[n+1] = 0;
    valr[n+1] = true;
    for(i=n;i>0;--i){
        r[i] = r[i+1];
        valr[i] = valr[i+1];
        if(s[i] == ')'){
            r[i]++;
        }
        else{
            r[i] --;
            if(r[i] < 0)
                valr[i] = false;
        }
    }
    int ans = 0;
    for(i=1;i<=n;++i){
        if(vall[i-1] && valr[i+1]){
            if(abs(l[i-1] - r[i+1]) == 1){
                if(l[i-1] > r[i+1])
                    ans += s[i] == '(';
                else
                    ans += s[i] == ')';
            }
        }
    }
    printf("%d\n", ans);
	return 0;
}