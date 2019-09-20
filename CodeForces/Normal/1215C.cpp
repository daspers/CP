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
char a[200002];
char b[200002];
int cnt[2];

int main(){
	scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    for(int i=0;i<n;++i){
        cnt[a[i]-'a']++;
        cnt[b[i]-'a']++;
    }
    if((cnt[0] & 1) || (cnt[1] & 1)) {
        return puts("-1"), 0;
    }
    queue<int> c1, c2;
    vector<pii> ans;
    for(int i=0;i<n;++i){
        if(a[i] != b[i]){
            if(a[i] == 'a'){
                c1.push(i);
            }
            else {
                c2.push(i);
            }
        }
    }
    while(c1.size() > 1){
        int x = c1.front(); c1.pop();
        int y = c1.front(); c1.pop();
        ans.pb({x, y});
    }
    while(c2.size() > 1){
        int x = c2.front(); c2.pop();
        int y = c2.front(); c2.pop();
        ans.pb({x, y});
    }
    if(!c1.empty() && !c2.empty()){
        int x = c1.front(); c1.pop();
        int y = c2.front(); c2.pop();
        ans.pb({x, x});
        ans.pb({x, y});
    }
    else if(!c1.empty() || !c2.empty()){
        return puts("-1"), 0;
    }
    printf("%d\n", (int)ans.size());
    for(pii x : ans){
        printf("%d %d\n", x.fi+1, x.se+1);
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