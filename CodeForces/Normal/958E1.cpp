#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
 
const ll mod = 1e9+7;
const double pi = acos(-1);

int n,t,i,j,k;
int r, b;
pair<float, float> a[11], c[11];
int arr[11];
bool vis[11], bisa;

bool get_line_intersection(float p0_x, float p0_y, float p1_x, float p1_y, 
    float p2_x, float p2_y, float p3_x, float p3_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        return 1;
    }

    return 0; // No collision
}

void btck(int idx){
	if(idx == r){
		for(int i=0;i<r;i++){
			for(int j=i+1;j<r;j++){
				if(get_line_intersection(a[i].fi, a[i].se, c[arr[i]].fi, c[arr[i]].se,
										 a[j].fi, a[j].se, c[arr[j]].fi, c[arr[j]].se))
					return;
			}
		}
		bisa = true;
		return;
	}
	for(int i=0;i<r;i++){
		if(vis[i]){
			arr[idx] = i;
			vis[i] = false;
			btck(idx+1);
			vis[i] = true;
			if(bisa)
				return;
		}
	}
}

int main(){
	memset(vis, true, sizeof vis);
	scanf("%d %d", &r, &b);
	for(i=0;i<r;i++)
		scanf("%f %f", &a[i].fi, &a[i].se);
	for(i=0;i<b;i++)
		scanf("%f %f", &c[i].fi, &c[i].se);
	if(r!=b)
		return puts("No");
	bisa = false;
	btck(0);
	if(bisa)
		puts("Yes");
	else
		puts("No");
	return 0;
}