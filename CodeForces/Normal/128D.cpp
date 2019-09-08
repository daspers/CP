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
int a[100003];
int cnt[100003];
vector<int> v;

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1;i<v.size();++i){
        if(v[i] - v[i-1] > 1) return puts("NO"), 0;
    }
    for(int i=0;i<n;++i) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        cnt[a[i]]++;
    }
    cnt[0] -= 1;
    cnt[v.size()-1] -= 1;
    for(int i=1;i+1<v.size();++i){
        if(cnt[i] < 2) return puts("NO"), 0;
        cnt[i] -= 2;
    }
    for(int i=1;i<v.size();++i){
        if(cnt[i-1] == 0) continue;
        if(cnt[i] < cnt[i-1]) return puts("NO"), 0;
        cnt[i] -= cnt[i-1];
        cnt[i-1] = 0;
    }
    for(int i=0;i<v.size();++i){
        if(cnt[i]) return puts("NO"), 0;
    }
    puts("YES");
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