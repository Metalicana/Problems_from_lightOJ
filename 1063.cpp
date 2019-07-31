#include <bits/stdc++.h>
using namespace std;
#define maxn 10009
int d[maxn],timee,n,m,a,b,low[maxn],parent[maxn],nc,ans,child[maxn];
vector <int> g[maxn];
bool ap[maxn],visited[maxn];
void fap(int u)
{
    visited[u]=1;
    timee++;
    d[u] = low[u] = timee;
    for(int i=0;i < g[u].size();i++)
    {
        if(g[u][i]==parent[u])continue;//nijer bap ke process korbo ken
        if(visited[g[u][i]])//back edge
        {
            low[u] = min(low[u],d[g[u][i]]);
        }
        else
        {
            parent[g[u][i]] = u;
            fap(g[u][i]);
            low[u] = min(low[u],low[g[u][i]]);
            if(d[u]<=low[g[u][i]] && u != 1)
            {
                ap[u]=1;
            }
            child[u]++;
        }
        if(child[u] > 1 && u == 1)ap[u]=1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        memset(d,0,sizeof d);
        memset(visited,0,sizeof visited);
        memset(low,0,sizeof low);
        memset(ap,0,sizeof ap);
        memset(child,0,sizeof child);
        for(int w=0;w<maxn;w++)g[w].clear();
        timee = 0;
        ans = 0;
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        fap(1);
        for(int w=1;w<=n;w++)
        {
            if(ap[w])
            {
                ans++;
            }
        }
        printf("Case %d: %d\n",test,ans);


    }
    return 0;
}
