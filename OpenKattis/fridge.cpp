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
char s[1005];
int cnt[10], cc[10];

int main(){
	scanf("%s", s);
    n = strlen(s);
    memset(cnt, 0, sizeof cnt);
    for(i=0;i<n;++i){
        cnt[s[i] - '0']++;
    }
    cnt[0]++;
    int mi = min_element(cnt, cnt + 10) - cnt;
    if(mi == 0){
        printf("1");
        for(int i=0;i<cnt[mi];++i){
            printf("%d", mi);
        }
        puts("");
    }
    else{
        for(int i=0;i<=cnt[mi];++i){
            printf("%d", mi);
        }
        puts("");
    }
	return 0;
}

/* Template Function */
void printArray(int * a, int n){
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