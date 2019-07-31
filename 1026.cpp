#include <bits/stdc++.h>
using namespace std;
#define maxn 10009
#define pii pair<int,int>
int a,b,m,n,o,timee,root;
vector <int> g[maxn],kraig[maxn];
vector<pii> poopoo;
short parent[maxn],child[maxn],low[maxn],d[maxn];
bool vis[maxn];
void fab(int u)
{
    vis[u]=1;
    timee++;
    d[u]=low[u]=timee;
    for(int i=0; i<g[u].size(); i++)
    {
        if(parent[u] == g[u][i])continue;
        if(vis[g[u][i]])//backedge
        {
            low[u]=min(low[u],d[g[u][i]]);
        }
        else
        {
            parent[g[u][i]] = u;
            fab(g[u][i]);
            low[u]=min(low[u],low[g[u][i]]);
            child[u]++;
            if(d[u] < low[g[u][i]])
            {
                kraig[min(u,g[u][i])].push_back(max(u,g[u][i]));
                //poopoo.push_back(pii(min(u,g[u][i]),max(u,g[u][i])));
                o++;
            }
        }
    }
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        for(int w=0; w<maxn; w++)g[w].clear();
        for(int w=0; w<maxn; w++)kraig[w].clear();
        //poopoo.clear();
        memset(parent,-1,sizeof parent);
        memset(child,0,sizeof child);
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof vis);
        memset(low, maxn+maxn, sizeof low);
        timee = 0;
        scanf("%d",&n);
        char putki[10005];
        for(int w=0; w<n; w++)
        {
            scanf("%d%s",&a,putki);
            o = atoi(&putki[1]);
            while(o--)
            {
                scanf("%d",&b);
                g[a].push_back(b);
                //g[b].push_back(a);
            }
        }
        o = 0;
        for(int w=0; w<n; w++)
        {
            if(!vis[w])
            {
                root = w;
                fab(w);
            }
        }

        printf("Case %d:\n",test);
        printf("%d critical links\n",o);

        for(int w=0; w<n; w++)
        {
            sort(kraig[w].begin(),kraig[w].end());
            for(int q=0; q<kraig[w].size(); q++)
            {
                printf("%d - %d\n",w,kraig[w][q]);
            }

        }
        /*sort(poopoo.begin(),poopoo.end());
        for(int i=0; i<poopoo.size(); i++)
        {
            printf("%d - %d\n",poopoo[i].first,poopoo[i].second);
        }*/
    }
    return 0;
}
