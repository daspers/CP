#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct nari{
	int d;
	char t;
} *a;

bool *b;
long ma,mi;
vector<int> p;
int z,n,r,y,m,v;

void permutation(char prev, int gain, int i, int x){
	if(i<r){
		for(int j=0;j<n;j++){
			if(b[j]){
				if(prev=='P')
					v=a[j].d*2;
				else if(prev=='L')
					v=a[j].d/2;
				else
					v=a[j].d;
				v+=gain;
				b[j]=false;
				if(a[j].t=='Y')
					permutation(a[j].t,gain+y,i+1,x+v);
				else
					permutation(a[j].t,gain,i+1,x+v);
				b[j]=true;
			}
		}
	}
	else{
		p.push_back(x);
	}
}

bool FS(long a, long b){
	return a>b;
}

int main(){
	string v;
	cin>>v>>z;
	cin>>n>>r>>y>>m;
	a=new nari [n];
	b=new bool [n];
	long h, count, c,k=0,mid;
	for(int i=0;i<n;i++){
		cin>>a[i].d>>a[i].t;
		b[i]=true;
	}
	permutation(' ',0,0,0);
	sort(p.begin(),p.end(),FS);
	c=p.size();
	for(int i=0;i<m;i++){
		cin>>h;
		count=0;
		if(h<=p[c-1]){
			count = c;
			while(h==p[count-1])
				count--;
		}
		else if(h<p[0]){
			mi=0;
			ma=c-1;
			mid=(mi+ma)/2;
			while(!(p[mid]>h&&p[mid+1]<=h)){
				if(p[mid]<=h){
					ma=mid;
				}
				else if(p[mid+1]>h){
					mi=mid+1;
				}
				mid=(mi+ma)/2;
			}
			count = mid+1;
		}
		cout<<count<<endl;
	}
	return 0;
}
