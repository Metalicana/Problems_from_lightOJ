#include <bits/stdc++.h>
using namespace std;
#define maxn 30009
int n,m,k,x,y,c;
vector <int> g[maxn];
vector <int> cost[maxn];
pair <int,int> s;
bool color[maxn];
int dst[maxn];

void dfs(int u)
{
    color[u]=1;
    for(int w=0;w<g[u].size();w++)
    {
        if(color[g[u][w]]==0)
        {
            s.first = u;
            s.second = g[u][w];
            dst[g[u][w]] = dst[u]+cost[u][w];
            dfs(g[u][w]);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        for(int w=0;w<maxn;w++)g[w].clear();
        for(int w=0;w<maxn;w++)cost[w].clear();
        for(int w=0;w<n-1;w++)
        {
            scanf("%d%d%d",&x,&y,&c);
            g[x].push_back(y);
            g[y].push_back(x);
            cost[x].push_back(c);
            cost[y].push_back(c);
        }
        memset(color,0,sizeof color);
        memset(dst,0,sizeof dst);
        dfs(0);
        int de=0;
        int gea;
        for(int w=0;w<n;w++)
        {
            if(dst[w] > de)
            {
                de = dst[w];
                gea = w;
            }
        }
        memset(dst,0,sizeof dst);
        memset(color,0,sizeof color);
        dfs(gea);
        int dee = 0;
        for(int w=0;w<n;w++)
        {
            if(dst[w]>dee)dee=dst[w];
        }
        printf("Case %d: %d\n",test,dee);
    }
    return 0;
}
