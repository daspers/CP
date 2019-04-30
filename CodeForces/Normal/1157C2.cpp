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

int main(){
	scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d", a+i);
    }
    int ans = 0;
    string s = "";
    int pre = 0;
    for(i=0,j=n-1;i<=j;){
        if(a[i] == a[j] && pre < a[i]){
            int cntl=1, cntr=1;
            for(int k=1;i+k<=j;++k){
                if(a[i+k] <= a[i+k-1]){
                    cntl=k;
                    break;
                }
            }
            for(int k=1;j-k>=i;++k){
                if(a[j-k] <= a[j-k+1]){
                    cntr=k;
                    break;
                }
            }
            if(cntl >= cntr){
                ans += cntl;
                for(int k=0;k<cntl;++k){
                    s += 'L';
                }
            }
            else{
                ans += cntr;
                for(int k=0;k<cntr;++k){
                    s += 'R';
                }
            }
            break;
        }
        if(a[i] < a[j] && pre < a[i]){
            ans++;
            s += 'L';
            pre = a[i];
            ++i;
        }
        else if(a[i] > a[j] && pre < a[j]){
            ans++;
            s += 'R';
            pre = a[j];
            --j;
        }
        else{
            if(pre < a[i]){
                ans++;
                s += 'L';
                pre = a[i];
                ++i;
            }
            else if(pre < a[j]){
                ans++;
                s += 'R';
                pre = a[j];
                --j;
            }
            else{
                break;
            }
        }
    }
    printf("%d\n", ans);
    printf("%s\n", s.data());
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