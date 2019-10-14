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
char s[200003];
int cnt[200003][5];
int ri[200003][5];
int le[200003][5];
int mep[256];

bool isVowel(char c){
    return c == 'a' || c=='i' || c=='u'||c=='e'||c=='o';
}



int main(){
    mep['a'] = 0; mep['i'] = 1; mep['u'] = 2; mep['e'] = 3; mep['o'] = 4;
	scanf("%s", s+1);
    n = strlen(s+1);
    memset(cnt, 0, sizeof cnt);
    for(int i=1;i<=n;++i){
        if(s[i] == 'a'){
            cnt[i][0]++;
        }
        else if(s[i] == 'i'){
            cnt[i][1]++;
        }
        else if(s[i] == 'u'){
            cnt[i][2]++;
        }
        else if(s[i] == 'e'){
            cnt[i][3]++;
        }
        else if(s[i] == 'o'){
            cnt[i][4]++;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<5;++j){
            cnt[i][j] += cnt[i-1][j];
        }
    }
    for(int i=0;i<5;++i){
        ri[n+1][i] = n+1;
    }
    for(int i=n;i>=1;--i){
        for(int j=0;j<5;++j){
            ri[i][j] = ri[i+1][j];
        }
        if(s[i] == 'a'){
            ri[i][0] = i;
        }
        else if(s[i] == 'i'){
            ri[i][1] = i;
        }
        else if(s[i] == 'u'){
            ri[i][2] = i;
        }
        else if(s[i] == 'e'){
            ri[i][3] = i;
        }
        else if(s[i] == 'o'){
            ri[i][4] = i;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;++i){
        int r = i;
        for(int j=0;j<5;++j){
            r = max(r, ri[i][j]);
        }
        if(r > n) break;
        ans += n - r + 1;
    }
    printf("%lld\n", ans);
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