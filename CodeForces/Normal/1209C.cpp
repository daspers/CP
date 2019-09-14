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
char ans[200003];
int cnt[10];

int main(){
	scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", s);
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<n;++i){
            cnt[s[i]-'0']++;
        }
        int ma1 = -1;
        int mi1 = -1;
        int ma2 = -1;
        int mi2 = -1;
        int cma = 9;
        bool bisa = true;
        for(int i=n-1;i>=0;--i){
            while(!cnt[cma]){
                cma--;
            }
            if(s[i] - '0' == cma){
                ans[i] = '2';
                if(mi2 == -1){
                    ma2 = mi2 = s[i]-'0';
                }
                else {
                    mi2 = min(mi2, s[i]-'0');
                    ma2 = max(ma2, s[i]-'0');
                }
                cnt[s[i]-'0']--;
            }
            else {
                ans[i] = '1';
                if(mi1 == -1){
                    ma1 = mi1 = s[i]-'0';
                }
                else {
                    if(s[i]-'0' > mi1) {
                        bisa = false;
                    }
                    mi1 = min(mi1, s[i]-'0');
                    ma1 = max(ma1, s[i]-'0');
                }
            }
        }
        ans[n] = 0;
        printf("%s\n", bisa? ans : "-");
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