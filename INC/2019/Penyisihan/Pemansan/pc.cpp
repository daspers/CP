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
char s[100];

int main(){
    ll x;
	scanf("%lld", &x);
    scanf("%s", s);
    n = strlen(s);
    ll tmp = x;
    string ss = s;
    string w = "";
    do{
        w += char((tmp%2) +'0');
        tmp /= 2;
    }while(tmp);
    reverse(w.begin(), w.end());
    // cerr<<w<<" "<<ss<<endl;
    int ans = 0;
    while(ss.size() > w.size()){
        for(int i=1;i<ss.size();++i){
            if(ss[i] == '1' || i+1 == ss.size()){
                ans++;
                ss.erase(ss.begin() + i);
                break;
            }
        }
    }
    // cerr<<w<<" "<<ss<<endl;
    if(ss.size() == w.size()){
        if(ss > w){
            ans++;
        }
    }
    printf("%d\n", ans);
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