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
char s[1002];
char r[1002];

int main(){
	scanf("%s", s);
	n = strlen(s);
	memset(r, 0, sizeof r);
    for(i=0,j=0;i<n;){
		// cerr<<i<<" "<<j<<endl;
		if(i + 2 < n){
			if(s[i] == '%'){
				if(s[i+1] == '2'){
					if(s[i+2]=='0'){
						r[j++] = ' ';
						i+=3;
					}
					else if(s[i+2] == '1'){
						r[j++] = '!';
						i+=3;
					}
					else if(s[i+2] == '2'){
						r[j++] = '\"';
						i+=3;
					}
					else if(s[i+2] == '7'){
						r[j++] = '\'';
						i+=3;
					}
					else if(s[i+2] == '8'){
						r[j++] = '(';
						i+=3;
					}
					else if(s[i+2] == '9'){
						r[j++] = ')';
						i+=3;
					}
					else if(s[i+2] == 'C'){
						r[j++] = ',';
						i+=3;
					}
					else{
						r[j++] = s[i++];
					}
				}
				else if(s[i+1] == '3'){
					if(s[i+2]=='F'){
						r[j++] = '?';
						i+=3;
					}
					else{
						r[j++] = s[i++];
					}
				}
				else{
						r[j++] = s[i++];
				}
			}
			else{
				r[j++] = s[i++];
			}
		}
		else{
			r[j++] = s[i++];
		}
	}
	n = strlen(r);
	stack<int> st;
	for(int i=0;i<n;++i){
		if(r[i] == '('){
			st.push(i);
		}
		else if(r[i] == ')'){
			int le = st.top();
			st.pop();
			reverse(r+le+1, r+i);
		}
	}
	for(int i=0;i<n;++i){
		if(r[i] !='(' && r[i] !=')')
			printf("%c", r[i]);
	}
	puts("");
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