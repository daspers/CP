#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool isABigger(string a, string b){
	int i=0;
	while(a[i]==b[i] && i<a.size() && i<b.size()){
		i++;
	}
	if(i == a.size())
		return false;
	if(i==b.size())
		return true;
	return a[i]>b[i];
}

int main(){
	long n,m,k;
	cin >>n>>m;
	string t[n], a[n], c;
	for(long i=0;i<n;i++){
		cin>>t[i]>>a[i];
	}
	bool f=0;
	for(long i=0;i<m;i++){
		cin>>c;
		f=0;
		int ma = n-1, mi = 0, mid;
		if(t[ma]==c){
			mid=ma;
		}
		else if(t[mi]==c){
			mid=mi;
		}
		else{
			mid = (ma+mi)/2;
			while (t[mid]!=c){
				if(mid==ma || mid==mi)
					break;
				if(isABigger(c,t[mid])){
					mi = mid;
					mid = (ma+mi)/2;
				}
				else{
					ma = mid;
					mid = (ma+mi)/2;
				}
			}
		}
		if(t[mid]!=c)
			cout<<"NIHIL\n";
		else
			cout<<a[mid]<<"\n";
	}
	return 0;
}
