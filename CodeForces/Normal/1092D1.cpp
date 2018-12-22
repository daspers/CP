#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, i, j;
int a[200005];
int b[200005];

int main(){
    scanf("%d", &n);
    for(i=0;i<n;++i){
        scanf("%d", a+i);
        a[i] &= 1;
    }
    if(n==1) return puts("YES") & 0;
    if(n==2) return puts(a[0]==a[1] ? "YES" : "NO") & 0;
    int len = 1;
    queue<int> q;
    for(i=1;i<n;++i){
        if(a[i] != a[i-1]){
            q.push(len);
            len = 1;
        }
        else len++;
    }
    q.push(len);
    int now = -1;
    stack<int> s;
    while(!q.empty()){
        if(s.empty()){
            if(now == -1){
                s.push(q.front());
                q.pop();
            }
            else{
                s.push(now);
                now = -1;
            }
        }
        else if(now == -1){
            now = q.front();
            q.pop();
        }
        else{
            if(now%2 == 0){
                now += s.top();
                now += q.front();
                s.pop();
                q.pop();
            }
            else{
                s.push(now);
                now =-1;
            }
        }
    }
    if(now != -1)
        s.push(now);
    int cnt = 0;
    while(!s.empty()){
        cnt += s.top() & 1;
        s.pop();
    }
    puts(cnt > 1? "NO" : "YES");
    return 0;
}