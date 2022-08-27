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
int m, x;
int a[2002][2002];
int cnt[2002][2002];
ll sum[2002][2002];
// int pcnt[2002][2002];
// ll psum[2002][2002];

int main(){
	scanf("%d %d %d", &n, &m, &x);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d", a[i]+j);
        }
    }
    ll ans = 1e9;
    pair<pii, pii> b;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i][j] > x) {
                int tr = (a[i][j] + x - 1) / x;
                if(tr < ans) {
                    ans = tr;
                    b = {{i,j},{i,j}};                
                }
                a[i][j] = -1;
            }
        }
    }
    memset(cnt, 0, sizeof cnt);
    memset(sum, 0, sizeof sum);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cnt[i][j]=(a[i][j] == -1) + cnt[i-1][j];
            sum[i][j]=sum[i-1][j] + max(a[i][j], 0);
        }
    }
    if(ans == 2) goto done;

    // if(n <= 300 && m <= 300) {
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                ll csum = 0;
                for(int k=1, l=1;k<=m;){
                    if(cnt[j][k] - cnt[i-1][k]) {
                        if(l == k) {
                            l = ++k;
                            csum = 0;
                        }
                        else {
                            csum -= cnt[j][l] - cnt[i-1][l];
                            ++l;
                        }
                    }
                    else if(k > l) {
                        ll tr = (csum + x - 1) / x;
                        if(tr >= ans) {
                            csum -= cnt[j][l] - cnt[i-1][l];
                            ++l;
                        }
                        else if(tr == 1) {
                            csum += sum[j][k] - sum[i-1][k];
                            ++k;
                        }
                    }
                    else {
                        csum += sum[j][k] - sum[i-1][k];
                        ++k;
                    }
                    if(k > l && csum > x) {
                        ll tr = (csum + x - 1) / x;
                        ans = tr;
                        b = {{i, l}, {j, k-1}};
                        if(ans == 2) goto done;
                    }
                }
            }
        }

    // }
    // else {
    //     for(int i=1;i<=n;++i){
    //         for(int j=1;j<=m;++j){
    //             cnt[i][j] = (a[i][j] == -1) + cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
    //             sum[i][j] = max(a[i][j], 0) + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    //         }
    //     }
    //     for(int i=1;i<=n;++i){
    //         for(int j=1;j<=m;++j){
    //             for(int k=i;k<=n;++k){
    //                 if(cnt[k][j] - cnt[i-1][j]) break;
    //                 ll csum=0, ccnt=0, tr=0;
    //                 int  l = j, r = m;
    //                 while(l < r) {
    //                     int mid = (l + r) / 2;
    //                     csum = sum[k][mid] - sum[k][j-1] - sum[i-1][mid] + sum[i-1][j-1];
    //                     ccnt = cnt[k][mid] - cnt[k][j-1] - cnt[i-1][mid] + cnt[i-1][j-1];
    //                     if(ccnt > 0) {
    //                         r = mid - 1;
    //                     }
    //                     else {
    //                         tr = (csum + x - 1) / x;
    //                         if(tr >= ans) {
    //                             r = mid - 1;
    //                         }
    //                         else if(tr == 1){
    //                             l = mid + 1;
    //                         }
    //                         else {
    //                             r = mid;
    //                         }
    //                     }
    //                 }
    //                 if(r < j) continue;
    //                 ccnt = cnt[k][r] - cnt[k][j-1] - cnt[i-1][r] + cnt[i-1][j-1];
    //                 if(!ccnt){
    //                     csum = sum[k][r] - sum[k][j-1] - sum[i-1][r] + sum[i-1][j-1];
    //                     tr = (csum + x - 1) / x;
    //                     if(tr < ans && tr > 1) {
    //                         ans = tr;
    //                         b = {{i,j},{k,r}};
    //                         if(ans == 2) goto done;
    //                     }
    //                 }
    //                 // for(int l=j;l<=m;++l){
    //                 //     if(cnt[k][l] - cnt[i-1][l]) break;
    //                 //     csum += sum[k][l] - sum[i-1][l];
    //                 //     ll tr = (csum + x - 1) / x;
    //                 //     if(tr > 1) {
    //                 //         if(tr < ans){
    //                 //             ans = tr;
    //                 //             b = {{i,j},{k,l}};
    //                 //             if(ans == 2) goto done;
    //                 //         }
    //                 //         break;
    //                 //     }
    //                 // }
    //             }
    //         }
    //     }
    // }


    done:

    printf("%lld\n", ans);
    printf("%d %d %d %d\n", b.fi.fi, b.fi.se, b.se.fi, b.se.se);
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