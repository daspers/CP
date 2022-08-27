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
string a[51];
int st[51], ed[51];

bool check(int *pt){
    for(int i=0;i<n;++i){
        if(a[i][pt[i]] != '*') return true;
    }
    return false;
}

int main(){
    cin>>t;
    for(int cc=1;cc<=t;++cc){
        cout<<"Case #"<<cc<<": ";
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        vector<char> suff, pref;
        bool possible = true;

        for(int i=0;i<n;++i) st[i] = 0;
        while(check(st)){
            char c = 0;
            for(int i=0;i<n;++i){
                if(a[i][st[i]] == '*') continue;
                if(c && a[i][st[i]] != c){
                    possible = false;
                    break;
                }
                c = a[i][st[i]++];
            }
            if(c) pref.pb(c);
        }

        if(possible){
            for(int i=0;i<n;++i) ed[i] = (int)a[i].size() - 1 ;
            while(check(ed)){
                char c = 0;
                for(int i=0;i<n;++i){
                    if(a[i][ed[i]] == '*') continue;
                    if(c && a[i][ed[i]] != c){
                        possible = false;
                        break;
                    }
                    c = a[i][ed[i]--];
                }
                // debug2(c, possible);
                if(c) suff.pb(c);
            }
        }

        if(!possible) cout<<"*\n";
        else {
            reverse(suff.begin(), suff.end());
            for(char x : pref) cout<<x;
            for(int i=0;i<n;++i){
                for(int j=st[i]+1;j<ed[i];++j){
                    if(a[i][j] == '*') continue;
                    cout<<a[i][j];
                }
            }
            for(char x : suff) cout<<x;
            cout<<"\n";
        }
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