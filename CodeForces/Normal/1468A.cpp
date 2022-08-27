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
int a[500003];

int solve(const vector<int>& input, vector<int>& solution, vector<int>& indices)
{
    vector<int> magic;
    vector<int> magici;
    vector< vector<int> > history; // OPTIONAL
    vector< vector<int> > historyi; // OPTIONAL
    for (int i=0;i<input.size();++i) {
        int x = input[i];
        vector<int>::iterator it = upper_bound(magic.begin(), magic.end(), x);
        if (it == magic.end()) {
            magic.push_back(x);
            magici.push_back(i);
            history.push_back(vector<int>(1, x)); // OPTIONAL
            historyi.pb(vector<int>(1, i));
        }
        else {
            *it = x;
            magici[it-magic.begin()] = i;
            history[it-magic.begin()].push_back(x); // OPTIONAL
            historyi[it-magic.begin()].pb(i);
        }
    }
    
    // OPTIONAL
    {
        int result = magic.size();
        solution.resize(result);
        indices.resize(result);
        solution.back() = magic.back();
        for (int i=result-2; i>=0; i--) {
            auto it = upper_bound(history[i].rbegin(), history[i].rend(), solution[i+1]);
            it --;
            solution[i] = *it;
        }
        for(int i=(int)input.size()-1, j=result-1;i>=0 && j>=0;--i) {
            if(input[i] == solution[j]){
                indices[j] = i;
                j--;
            }
        }
    }
    
    return magic.size();
}

int main(){
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0;i<n;++i) {
            scanf("%d", a+i);
        }
        vector<int> v;
        vector<int> w;
        // for (int i=0;i<n;++i) {
        //     int x = a[i];
        //     vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
        //     if (it == v.end()) {
        //         v.pb(x);
        //         w.pb(i);
        //     }
        //     else {
        //         *it = x;
        //         w[it-v.begin()] = i;
        //     }
        // }

        solve(vector<int>(a, a+n), v, w);

        printArray(v);
        printArray(w);
        vector<int> u;
        for(int i=0;i<w[0];++i) {
            if (a[i] >= v[0]) {
                u.pb(a[i]);
                break;
            }
        }
        u.pb(v[0]);
        for(int i=1;i<w.size();++i){
            for(int j=w[i-1]+1;j<w[i];++j) {
                if(a[j] >= v[i-1] && a[j] >= v[i]) {
                    u.pb(a[j]);
                    break;
                }
            }
            u.pb(v[i]);
        }
        for(int i=w[(int)w.size()-1]+1;i<n;++i) {
            if (a[i] >= v[(int)w.size()-1]) {
                u.pb(a[i]);
                break;
            }
        }
        printArray(u);
        printf("%d\n", (int)u.size());
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