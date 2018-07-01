#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;

int const mod = 1e9+7;

int n,i,j,k,t,p;
string s;
deque<int> dq;

int main(){
	// scanf("%d", &n);
	cin>>n;
	for(i=0;i<n;++i){
		cin>>s;
		if(s=="push_back"){
			cin>>t;
			dq.push_back(t);
		}
		else if(s=="push_front"){
			cin>>t;
			dq.push_front(t);
		}
		else if(s=="pop_back")
			dq.pop_back();
		else
			dq.pop_front();
	}
	while(!dq.empty()){
		cout<<dq.front()<<"\n";
		dq.pop_front();
	}
	return 0;
}