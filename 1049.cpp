#include <bits/stdc++.h>
using namespace std;
#define maxn 105
#define inf (1<<30)
vector <int> g[maxn],h[maxn];
vector <int> neww[maxn];
vector <int> trans[maxn];
bool vis[maxn],color[maxn];
int c[maxn],edge[maxn][maxn];
int begg[maxn][maxn];
int a,b,cee,d,e,n,v;
stack <int> stac;
void dfs(int u)
{
    color[u]=1;
    for(int w=0; w<g[u].size(); w++)
    {
        v = g[u][w];
        if(color[v]==0)dfs(v);
    }
    stac.push(u);

}
void dfs2(int u,int mark)
{
    c[u]=mark;
    vis[u]=1;
    for(int w=0; w<h[u].size(); w++)
    {
        v = h[u][w];
        if(vis[v]==0)dfs2(v,mark);
    }
}
void scc()
{
    while(!stac.empty())stac.pop();
    for(int w=1; w<=n; w++)
    {
        if(color[w]==0)
        {
            dfs(w);
        }
    }
    int mark = 0;
    while(!stac.empty())
    {
        int u = stac.top();
        stac.pop();
        if(vis[u]==0)
        {
            mark++;
            dfs2(u,mark);
        }

    }
}
int dfs3(int u,int dest,int mark,int money,int baf)
{
    if(u == dest && mark == 1)return money;
    mark = 1;
    int p = inf;
    color[u]=1;
    for(int w=0;w<neww[u].size();w++)
    {
        v = neww[u][w];
        if(color[v]==0)
        {
            p = min(p,dfs3(v,dest,mark,money,u));
        }
        else if(color[v]==1 && v == dest && v!=baf)
        {
            return money;
        }
        else if(color[v]==1 && v!=baf)
        {
            p = min(p,dfs3(v,dest,mark,money,u));
        }

    }
    for(int w=0;w<trans[u].size();w++)
    {
        v = trans[u][w];
        if(color[v]==0)
        {
            p = min(p,dfs3(v,dest,mark,money+begg[v][u],u));
        }
        else if(color[v]==1 &&v == dest && v!=baf)
        {
            return money + begg[v][u];
        }
        else if(color[v]==1 && v!=baf)
        {
            p = min(p,dfs3(v,dest,mark,money+begg[v][u],u));
        }
    }
    return p;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        for(int w=0; w<maxn; w++)g[w].clear();
        for(int w=0; w<maxn; w++)h[w].clear();
        for(int w=0; w<maxn; w++)neww[w].clear();
        for(int w=0; w<maxn; w++)trans[w].clear();
        memset(vis,0,sizeof vis);
        memset(color,0,sizeof color);
        scanf("%d",&n);
        pair <int,int> khela[maxn];
        for(int w=0; w<n; w++)
        {
            scanf("%d%d%d",&a,&b,&cee);
            g[a].push_back(b);
            h[b].push_back(a);
            edge[a][b]=cee;
            khela[w].first = a;
            khela[w].second = b;
        }
        scc();

        int notun_node=0;
        for(int w=0; w<n; w++)
        {
            if(c[khela[w].first] != c[khela[w].second])
            {
                notun_node++;
                neww[c[khela[w].first]].push_back(c[khela[w].second]);
                trans[c[khela[w].second]].push_back(c[khela[w].first]);
                begg[c[khela[w].first]][c[khela[w].second]] = edge[khela[w].first][khela[w].second];
            }
        }
        memset(color,0,sizeof color);
        int ans = 0;
        for(int w=1;w<=notun_node;w++)
        {
            if(color[w]==0)
            {
                ans += dfs3(w,w,0,0,0);
            }
        }
        printf("Case %d: %d\n",test,ans);



    }
    return 0;
}
