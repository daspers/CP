#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 2000000000000000000LL
#define EPS 1e-9
#define debug(a) cerr<<#a<<"="<<(a)<<"\n"
#define debug2(a, b) cerr<<#a<<"="<<(a)<<" ";debug(b)
#define debug3(a, b, c) cerr<<#a<<"="<<(a)<<" ";debug2(b, c)
#define debug4(a, b, c, d) cerr<<#a<<"="<<(a)<<" ";debug3(b, c, d)
#define debug5(a, b, c, d, e) cerr<<#a<<"="<<(a)<<" ";debug4(b, c, d, e)
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
void printArray(const T * a, int n, ostream& out = cerr);
template<class T>
void printArray(const vector<T> &arr, ostream& out = cerr);

const ll mod = 1e9+7;
const double PI = acos(-1);

int n,i,j,k,t;
int u;
int val[10002];
int slen[10002];
int rlen[10002];
char s[10002][20];
char r[10002][20];
int mi[26], ma[26], g[26];
// int dp[12][1<<10];
vector<int> digits;
vector<int> tests;

int count_digit(int val){
    int ans = 0;
    while(val) {
        val /= 10;
        ans++;
    }
    return ans;
}

bool check(int idx){
    for(int i=0;i<slen[idx];++i){
        int ch = s[idx][i] - 'A';
        if(g[ch] < r[idx][i]) return true;
        else if(g[ch] > r[idx][i]) return false;
    }
    return true;
}

int guess(int idx, int state){
    // debug2(idx, state);
    if(idx == digits.size()){
        // puts("masuk sih");
        for(int id : tests){
            if(!check(id)) return false;
        }
        return true;
    }
    int d = digits[idx];
    for(int i=mi[d];i<=ma[d];++i){
        int now = 1 << i;
        if(!(state & now)) continue;
        g[d] = i;
        if(guess(idx+1, state ^ now)) return true;
    }
    return false;
}

int main(){
    scanf("%d", &t);
    for(int cc=1;cc<=t;++cc){
        printf("Case #%d: ", cc);
        scanf("%d", &u);
        for(int i=0;i<26;++i) mi[i] = 0, ma[i] = 9;
        digits.clear();
        tests.clear();
        set<int> digit;
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        for(int i=0;i<10000;++i){
            scanf("%s %s", r[i], s[i]);
            slen[i] = strlen(s[i]);
            rlen[i] = strlen(r[i]);
            for(int j=0;j<slen[i];++j){
                digit.insert(s[i][j]-'A');
                cnt[s[i][j]-'A']++;
            }
            mi[s[i][0]-'A'] = 1;
            if(strcmp(r[i], "-1") == 0){
                continue;
            }
            for(int j=0;j<rlen[i];++j){
                r[i][j] -= '0';
            }
            if(slen[i] == rlen[i]){
                int ch = s[i][0] - 'A';
                ma[ch] = min(ma[ch], (int)r[i][0]);
                tests.pb(i);
            }
        }
        digits = vector<int>(digit.begin(), digit.end());
        // printArray(digits);
        // for(int x : digits){
        //     printf("%c: %d %d\n", x+'A', mi[x], ma[x]);
        // }
        for(int x : digits){
            printf("%c %d\n", x+'A', cnt[x]);
        }
        if(!guess(0, (1<<10)-1)) assert(false);
        for(int i=0;i<10;++i){
            for(int d : digits){
                if(g[d] == i){
                    printf("%c", d + 'A');
                }
            }
        }
        puts("");
    }
    return 0;
}

/* Template Function */
template<class T>
void printArray(const T * a, int n, ostream& out){
    for(int i=0;i<n;++i){
        out<<a[i]<<" ";
    }
    out<<endl;
}

template<class T>
void printArray(const vector<T> &arr, ostream& out){
    for(const T& x : arr){
        out<<x<<" ";
    }
    out<<endl;
}