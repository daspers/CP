#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=1e9;
const int maxn=2e5+5;
const ll mod=998244353;
//#define endl '\n'
#define bug cout<<"he"<<endl;
int n,m,S;
vector<int>G1[maxn],G2[maxn];
ll ans;
ll w[maxn],sum[maxn];

int low[maxn],dfn[maxn],times,q[maxn],head,scc_cnt,scc[maxn];
int sz[maxn];
void tarjan(int u,int f){
    dfn[u]=low[u]=++times;
    q[++head]=u;
    for(auto i:G1[u]){
        if(i==f)continue;
        if(!dfn[i]){
            tarjan(i,u);
            low[u]=min(low[u],low[i]);
        }
        else low[u]=min(low[u],dfn[i]);
    }
    if(low[u]==dfn[u]){
        scc_cnt++;
        while(true){
            int x=q[head--];
            scc[x]=scc_cnt;
            sz[scc_cnt]++;
            sum[scc_cnt]+=w[x];
            if(x==u)break;
        }
    }
}
void dfs1(int u,int f){
    for(auto i:G2[u]){
        if(i==f)continue;
        dfs1(i,u);
        if(sz[i]!=1){
            sum[u]+=sum[i],sum[i]=0;
            sz[u]+=sz[i];
        }
    }
}
void dfs2(int u,int f,ll now){
    now+=sum[u];
    ans=max(ans,now);
    for(auto i:G2[u]){
        if(i==f)continue;
        dfs2(i,u,now);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    tarjan(1,0);
    for(int i=1;i<=n;i++){
        for(auto v:G1[i]){
            if(scc[i]!=scc[v]){
                G2[scc[i]].push_back(scc[v]);
                cerr<<"("<<i<<"->"<<scc[i]<<") ("<<v<<"->"<<scc[v]<<")"<<endl;
            }
        }
    }
    cin>>S;
    S=scc[S];
    dfs1(S,0);
    dfs2(S,0,0);
    cout<<ans<<endl;
    return 0;
}
