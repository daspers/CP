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

struct dataset {
    double val[10];
    dataset(){
        for(int i=0;i<9;++i){
            val[i] = 0;
        }
    }
};

std::ostream& operator<<(std::ostream &o, const dataset& p)
{
    for(int i=0;i<10;++i){
        o<<p.val[i]<<" ";
    }
    return o << "\n";
}

int n,i,j,k,t;
int m;
char c;
vector<dataset> a;
string s;

double predict(const dataset &a, dataset &b) {
    double sum = 0;
    for(int i=0;i<9;++i){
        sum += a.val[i] * b.val[i];
    }
    double res = 1 / (1 + exp(-sum));
    return res;
}

double normalize(double val){
    return val > 0.5 ? 1 : 0;
}

dataset sgd(int st, int ed, double lr, int epoch){
    dataset model;
    // model.val[0] = 1;
    for(int i=0;i<epoch;++i){
        for(int j=st;j<=ed;++j){
            double res = predict(a[j], model);
            for(int k=0;k<9;++k){
                double exz = exp(a[j].val[9] * a[j].val[k]);
                model.val[k] = model.val[k] + lr * (a[j].val[k] * ((a[j].val[9]-1) * exz  + res)) / (exz + 1);
            }
        }
    }
    return model;
}

int main(){
    cin>>n>>c>>m;
    while(1){
        dataset x;
        cin>>s;
        if(s == "0") break;
        stringstream st (s);
        for(int i=1;i<10;++i){
            st>>x.val[i];
            st>>c;
        }
        // for(int i=1;i<9;++i){
        //     if(ma == mi){
        //         x.val[i] = 0;
        //     }
        //     else {
        //         x.val[i] = (x.val[i] - mi) / (ma - mi);
        //     }
        // }
        x.val[0] = 1;
        a.pb(x);
    }
    for(int i=1;i<9;++i){
        double mi, ma;
        for(int j=0;j<n+m;++j){
            if(j){
                mi = min(mi, a[j].val[i]);
                ma = max(ma, a[j].val[i]);
            }
            else{
                mi = ma = a[j].val[i];
            }
        }
        for(int j=0;j<n+m;++j){
            if(ma == mi){
                // assert(false);
                a[j].val[i] = 0;
            }
            else {
                a[j].val[i] = (a[j].val[i] - mi) / (ma - mi);
            }
        }
    }
    // for(dataset &x : a){
    //     cout<<x;
    // }

    dataset model = sgd(0, n-1, 0.1, 100);
    cout<<model;

    int correct = 0;
    for(int i=n;i<n+m;++i){
        if(fabs(normalize(predict(a[i], model)) - a[i].val[9]) < EPS) {
            correct++;
        }
    }

    double ans = 100.0*correct / m;
    cout<<"The Accuracy = "<<fixed<<setprecision(3)<<ans<<"%\n";

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