#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define INF 200000001
#define EPS 1e-9

typedef long long ll;
typedef complex<double> cd;

const ll mod = 1e9+7;
const double pi = acos(-1);

struct TRIE{
	TRIE *child[10];
	int val;
	TRIE(){
		init();
	}
	void insert(int idx, string::iterator begins, string::iterator ends){
		if(begins == ends){
			val = idx;
			return;
		}
		int transition = *begins-'0';
		if(child[transition]==NULL)
			child[transition] = new TRIE();
		child[transition]->insert(idx, begins+1, ends);
	}
	void clear(){
		for(int i=0;i<10;++i){
			if(child[i]!=NULL){
				child[i]->clear();
				delete child[i];
			}
		}
	}
	void init(){
		for(int i=0;i<10;++i)
			child[i] = NULL;
		val = -1;
	}
	void find(string::iterator begins, string::iterator ends, vector<int> &ans){
		if(val!=-1)
			ans.pb(val);
		if(begins==ends)
			return;
		int transition = *begins-'0';
		if(child[transition] != NULL)
			child[transition]->find(begins+1, ends, ans);
	}
};

int n,i,j,k,t;
string num, s[50000], ss;
char mep[256];
pii dp[105];
TRIE trie;

pii solve(int idx){
	pii &ans = dp[idx];
	if(ans.fi==-1){
		ans = {-2, -2};
		vector<int> candidate;
		trie.find(num.begin()+idx, num.end(), candidate);
		for(int i : candidate){
			pii tmp = solve(idx + s[i].size());
			if(tmp.fi==-2)
				continue;
			if(ans.fi==-2)
				ans = {i, tmp.se+1};
			else if(ans.se > tmp.se+1)
				ans = {i, tmp.se+1};
		}
	}
	return ans;
}

int main(){
	mep['i']=mep['j']='1';
	mep['a']=mep['b']=mep['c']='2';
	mep['d']=mep['e']=mep['f']='3';
	mep['g']=mep['h']='4';
	mep['k']=mep['l']='5';
	mep['m']=mep['n']='6';
	mep['p']=mep['r']=mep['s']='7';
	mep['t']=mep['u']=mep['v']='8';
	mep['w']=mep['x']=mep['y']='9';
	mep['o']=mep['q']=mep['z']='0';
	while(cin>>num, num!="-1"){
		memset(dp, -1, sizeof dp);
		cin>>n;
		for(i=0;i<n;++i){
			cin>>s[i];
			ss = s[i];
			for(char &c : ss){
				c = mep[c];
			}
			trie.insert(i, ss.begin(), ss.end());
		}
		dp[num.size()] = {0,0};
		if(solve(0).fi == -2)
			cout<<"No solution.\n";
		else{
			for(i=0;i<num.size();i+=s[dp[i].fi].size()){
				cout<<s[dp[i].fi]<<" ";
			}
			cout<<"\n";
		}
		trie.clear();
		trie.init();
	}
	return 0;
}