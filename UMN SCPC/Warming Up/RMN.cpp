// Problem Roman Number

#include <bits/stdc++.h>

using namespace std;

int w[256]={0};

int translate(string a){
	int k=0;
	for(int i=0;i<a.size();i++){
		if(i<a.size()-1){
			if(w[a[i+1]]>w[a[i]])
				k-=w[a[i]];
			else
				k+=w[a[i]];
		}
		else
			k+=w[a[i]];
	}
	return k;
}

string retranslate(int a){
	string b="";
	if(a>=1000){
		while(a>=1000){
			b+="M";
			a-=1000;
		}
	}
	if(a>=900){
		b+="CM";
		a-=900;
	}
	if(a>=500){
		b+="D";
		a-=500;
	}
	else if(a>=400){
		b+="CD";
		a-=400;
	}
	if(a>=100){
		while(a>=100){
			b+="C";
			a-=100;
		}
	}
	if(a>=90){
		b+="XC";
		a-=90;
	}
	if(a>=50){
		b+="L";
		a-=50;
	}
	else if(a>=40){
		b+="XL";
		a-=40;
	}
	if(a>=10){
		while(a>=10){
			b+="X";
			a-=10;
		}
	}
	if(a>=9){
		b+="IX";
		a-=9;
	}
	if(a>=5){
		b+="V";
		a-=5;
	}
	else if(a>=4){
		b+="IV";
		a-=4;
	}
	if(a>=1){
		while(a>=1){
			b+="I";
			a-=1;
		}
	}
	return b;
}

int main(){
	int t, c,d;
	string a,b;
	scanf("%d",&t);
	w['I']=1, w['V']=5, w['X']=10,w['L']=50,w['C']=100,w['D']=500,w['M']=1000;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		c=translate(a);
		d=translate(b);
		printf("Case #%d: ",i);
		cout<<retranslate(c+d)<<"\n";
	}
	return 0;
}
