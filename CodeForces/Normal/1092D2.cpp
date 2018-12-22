#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

int n, i, j;
int a[200005];
int b[200005];

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i)
        scanf("%d", a+i);
    if(n==1) return puts("YES") & 0;
    if(n==2) return puts(a[0]==a[1] ? "YES" : "NO") & 0;
    int len = 1;
    int ma = *max_element(a, a+n);
    queue<pii> q;
    for(i=1;i<n;++i){
        if(a[i] != a[i-1]){
            q.push({a[i-1], len});
            len = 1;
        }
        else len++;
    }
    q.push({a[n-1], len});
    q.push({ma, 1});
    pii now = {-1, -1};
    stack<pii> s;
    s.push({ma, 1});
    while(!q.empty()){
        if(s.empty()){
            if(now.fi == -1){
                s.push(q.front());
                q.pop();
            }
            else{
                s.push(now);
                now = {-1, -1};
            }
        }
        else if(now.fi == -1){
            now = q.front();
            q.pop();
        }
        else{
            if(now.se%2 == 0 && now.fi <= s.top().fi && now.fi <= q.front().fi){
                if(s.top().fi < q.front().fi){
                    now.fi = s.top().fi;
                    now.se += s.top().se;
                    s.pop();
                }
                else if(s.top().fi > q.front().fi){
                    now.fi = q.front().fi;
                    now.se += q.front().se;
                    q.pop();
                }
                else{
                    now.fi = q.front().fi;
                    now.se += q.front().se + s.top().se;
                    q.pop();
                    s.pop();
                }
            }
            else{
                s.push(now);
                now = {-1, -1};
            }
        }
    }
    if(now.fi != -1)
        s.push(now);
    int cnt = 0;
    while(!s.empty()){
        cnt += s.top().fi < ma;
        s.pop();
    }
    puts(cnt? "NO" : "YES");
    return 0;
}