#include <iostream>
#include <string>

using namespace std;

struct nilai{
	string p;
	int n1;
	int n2;
	int n3;
} *k, temp;

bool Abigger(nilai a, nilai b){
	if(a.n3==b.n3){
		if(a.n2==b.n2)
			return a.n1>b.n1;
		else
			return a.n2>b.n2;
	}
	else
		return a.n3>b.n3;
}

bool check(string x, int a){
	for(int i=0;i<a;i++){
		if(k[i].p==x){
			return true;
		}
	}
	return false;
}

int main(){
	int a,b,c;
	string x;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>c;
		cin>>x;
		k=new nilai [b];
		for(int j=0;j<b;j++){
			cin>>k[j].p>>k[j].n1>>k[j].n2>>k[j].n3;
		}
		for(int j=0;j<b-1;j++){
			int jmin=j;
			for(int l=j+1;l<b;l++){
				if(Abigger(k[l],k[jmin])){
					jmin=l;
				}
			}
			if(jmin!=j){
				temp=k[jmin];
				k[jmin]=k[j];
				k[j]=temp;
			}
		}
		if(check(x,c))
			cout<<"YA\n";
		else
			cout<<"TIDAK\n";
		delete[] k;
	}
	return 0;
}
