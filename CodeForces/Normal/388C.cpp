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
int l[102];
int a[102][102];

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", l+i);
        for(int j=0;j<l[i];++j){
            scanf("%d", a[i]+j);
        }
    }
    vector<int> v;
    int suma = 0;
    int sumb = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<l[i]/2;++j){
            suma += a[i][j];
            sumb += a[i][l[i]-1-j];
        }
        if(l[i]&1){
            v.pb(a[i][l[i]/2]);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i=0;i<v.size();++i){
        if(i&1){
            sumb += v[i];
        }
        else{
            suma += v[i];
        }
    }
    printf("%d %d\n", suma, sumb);
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