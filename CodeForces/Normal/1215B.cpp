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
int a[200002];
vector<int> v;
int cntr[200003];
int pcntr[200003];

int main(){
	scanf("%d", &n);
    v.pb(-1);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
        if(a[i] > 0) a[i] = 1;
        else if(a[i] < 0){
            a[i] = -1;
            v.pb(i);
        }
    }
    v.pb(n);
    ll totans = 1LL*n*(n+1)/2;
    ll neg = 0;
    for(int i=1;i+1<v.size();++i){
        cntr[i] = v[i+1] - v[i];
    }
    for(int i=(int)v.size() - 2;i>0;--i){
        pcntr[i] = cntr[i];
        if(i + 2 < (int)v.size() - 1){
            pcntr[i] += pcntr[i+2];
        }
    }
    for(int i=1;i+1<v.size();++i){
        int pre = v[i] - v[i-1];
        // cerr<<v[i]<<" "<<pre<<" "<<pcntr[i]<<endl;;
        neg += 1LL* pre * pcntr[i];
    }
    printf("%lld %lld\n", neg, totans - neg);
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