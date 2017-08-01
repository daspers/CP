#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int x1,y1,x2,y2,d1,d2;
	cin>> x1>>y1>>x2>>y2;
  d1=(x1>x2?x1-x2:x2-x1);
  d2=(y1>y2?y1-y2:y2-y1);
	cout<< d1+d2<<endl;
	return 0;
}
