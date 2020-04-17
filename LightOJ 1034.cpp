#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
vector <int> g[maxn],h[maxn],neww[maxn];
short color[maxn],c[maxn];
bool visited[maxn];
stack <int> stac;
int n,m,q,a,b,mark;
void dfs(int u)
{
    color[u]=1;
    for(int w=0; w<g[u].size(); w++)
    {
        if(color[g[u][w]] == 0)dfs(g[u][w]);
    }
    stac.push(u);
    return;

}
void dfs2(int u,int mark)
{
    c[u] = mark;
    visited[u]=1;
    for(int w=0; w<h[u].size(); w++)
    {
        if(!visited[h[u][w]])
        {
            dfs2(h[u][w],mark);
        }
    }
}
void scc()
{
    mark = 0;
    for(int w=1; w<=n; w++)
    {
        if(color[w]==0)dfs(w);
    }
    while(!stac.empty())
    {
        int u = stac.top();
        stac.pop();
        if(visited[u]==0)
        {
            mark++;
            dfs2(u,mark);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%d%d",&n,&m);
        for(int w=0; w<maxn; w++)g[w].clear();
        for(int w=0; w<maxn; w++)h[w].clear();
        for(int w=0; w<maxn; w++)neww[w].clear();
        while(!stac.empty())stac.pop();
        memset(color,0,sizeof color);
        memset(visited,0,sizeof visited);
        mark = 0;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            h[b].push_back(a);
        }
        scc();
        for(int w=1; w<=n; w++)
        {
            for(int q=0; q<g[w].size(); q++)
            {
                if(c[w]!=c[g[w][q]])
                {
                    neww[c[g[w][q]]].push_back(c[w]);
                }
            }
        }
        int k = 0;
        for(int w=1; w<=mark; w++)
        {
            if(neww[w].size()==0)k++;
        }
        printf("Case %d: %d\n",test,k);
    }


    return 0;
}
