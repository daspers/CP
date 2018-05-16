#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>

typedef long long ll;

const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k,m;
int a[100002];
char tp[100002];
bool sudah[100002];
vector<int> pal, luc, none, tluc, tpal;

bool isluck(int a){
	if(a==0)
		return false;
	while(a){
		if(a%10 != 4 && a%10 != 7)
			return false;
		a/=10;
	}
	return true;
}

bool ispal(int a){
	int rev = 0;
	int ta = a;
	while(a){
		rev = rev*10 + a%10;
		a/=10;
	}
	return rev == ta;
}

int main(){
	memset(sudah, false, sizeof sudah);
	scanf("%d %d", &n, &m);
	for(i=0;i<n;i++){
		scanf("%d", a+i);
		tp[i] = 0;
		if(ispal(a[i]))
			tp[i] |= 1;
		if(isluck(a[i]))
			tp[i] |= 2;
		if(tp[i]==1)
			pal.pb(i);
		else if(tp[i]==2)
			luc.pb(i);
		else
			none.pb(i);
	}
	if(n==1)
		return puts("No");
	if(pal.size() == 0 && luc.size()==0){
		return puts("Yes");
	}
	for(i=j=0;i<pal.size() && j<luc.size();){
		if(pal[i] < luc[j]){
			if(i+1<pal.size() && pal[i+1] - pal[i] <= m){
				i += 2;
				continue;
			}
			else if(i-1>=0 && pal[i]-pal[i-1] <= m){
				++i;
				continue;
			}
			else{
				int up = upper_bound(tpal.begin(), tpal.end(), pal[i] + m) - tpal.begin();
				int lo = lower_bound(tpal.begin(), tpal.end(), pal[i] - m) - tpal.begin();
				if(lo < up){
					++i;
					continue;
				}
			}
			int up = upper_bound(none.begin(), none.end(), pal[i] + m) - none.begin();
			int lo = lower_bound(none.begin(), none.end(), pal[i] - m) - none.begin();
			for(k = lo;k<up&&sudah[none[k]];++k);
			if(k == up)
				return puts("No");
			tpal.pb(none[k]);
			sudah[none[k]] = true;
			++i;
		}
		else{
			if(j+1<luc.size() && luc[j+1] - luc[j] <= m){
				j += 2;
				continue;
			}
			else if(j-1>=0 && luc[j]-luc[j-1] <= m){
				++j;
				continue;
			}
			else{
				int up = upper_bound(tluc.begin(), tluc.end(), luc[j] + m) - tluc.begin();
				int lo = lower_bound(tluc.begin(), tluc.end(), luc[j] - m) - tluc.begin();
				if(lo < up){
					++j;
					continue;
				}
			}
			int up = upper_bound(none.begin(), none.end(), luc[j] + m) - none.begin();
			int lo = lower_bound(none.begin(), none.end(), luc[j] - m) - none.begin();
			for(k = lo;k<up&&sudah[none[k]];++k);
			if(k == up)
				return puts("No");
			tluc.pb(none[k]);
			sudah[none[k]] = true;
			++j;
		}
	}
	while(i < pal.size()){
		if(i+1<pal.size() && pal[i+1] - pal[i] <= m){
			i += 2;
			continue;
		}
		else if(i-1>=0 && pal[i]-pal[i-1] <= m){
			++i;
			continue;
		}
		else{
			int up = upper_bound(tpal.begin(), tpal.end(), pal[i] + m) - tpal.begin();
			int lo = lower_bound(tpal.begin(), tpal.end(), pal[i] - m) - tpal.begin();
			if(lo < up){
				++i;
				continue;
			}
		}
		int up = upper_bound(none.begin(), none.end(), pal[i] + m) - none.begin();
		int lo = lower_bound(none.begin(), none.end(), pal[i] - m) - none.begin();
		for(k = lo;k<up&&sudah[none[k]];++k);
		if(k == up)
			return puts("No");
		tpal.pb(none[k]);
		sudah[none[k]] = true;
		++i;
	}
	while(j < luc.size()){
		if(j+1<luc.size() && luc[j+1] - luc[j] <= m){
			j += 2;
			continue;
		}
		else if(j-1>=0 && luc[j]-luc[j-1] <= m){
			++j;
			continue;
		}
		else{
			int up = upper_bound(tluc.begin(), tluc.end(), luc[j] + m) - tluc.begin();
			int lo = lower_bound(tluc.begin(), tluc.end(), luc[j] - m) - tluc.begin();
			if(lo < up){
				++j;
				continue;
			}
		}
		int up = upper_bound(none.begin(), none.end(), luc[j] + m) - none.begin();
		int lo = lower_bound(none.begin(), none.end(), luc[j] - m) - none.begin();
		for(k = lo;k<up&&sudah[none[k]];++k);
		if(k == up)
			return puts("No");
		tluc.pb(none[k]);
		sudah[none[k]] = true;
		++j;
	}
	puts("Yes");
	return 0;
}