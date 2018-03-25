#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

struct hitung{
	hitung(){
		for(int i=0;i<26;i++)
			c[i]=0;
	}
	hitung(const hitung& t){
		for(int i=0;i<26;i++)
			c[i]=t.c[i];
	}
	friend bool operator==(hitung& a, hitung& b){
		for(int i=0;i<26;i++){
			if(a.c[i]!=b.c[i])
				return false;
		}
		return true;
	}
	friend hitung operator-(const hitung& a, const hitung& b){
		hitung res;
		for(int i=0;i<26;i++)
			res.c[i]=a.c[i]-b.c[i];
		return res;
	}
	friend bool operator< (const hitung& a, const hitung& b){
		int i;
		for(i=0;i<26&&a.c[i]==b.c[i];i++);
		if(i==26)
			return false;
		return a.c[i]<b.c[i];
	}
	void add(int x){
		++c[x];
	}
	int c[26];
};

int n,t,j,i,k;
string a, b;
hitung sa[4002], sb[4002];
set<hitung> m;

int main(){
	cin>>a>>b;
	a="0"+a;
	b="0"+b;
	for(int i=1;i<a.size();i++){
		sa[i] = sa[i-1];
		sa[i].add(a[i]-'a');
	}
	for(int i=1;i<b.size();i++){
		sb[i] = sb[i-1];
		sb[i].add(b[i]-'a');
	}
	for(int i=min(a.size(), b.size())-1;i>0;i--){
		for(int j=1;j<=a.size()-i;j++){
			m.insert(hitung(sa[j+i-1]-sa[j-1]));
		}
		for(int j=1;j<=b.size()-i;j++){
			if(m.count(hitung(sb[j+i-1]-sb[j-1]))){
				printf("%d\n", i);
				return 0;
			}
		}
		m.clear();
	}
	puts("0");
	return 0;
}