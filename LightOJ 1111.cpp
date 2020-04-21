#include <bits/stdc++.h>
using namespace std;
#define maxn 1009
int n,m,k,x,y;
vector <int> g[maxn];
int friends[105];
int friends_paise[maxn];
int color[maxn];
void dfs(int u)
{
    color[u] = 1;
    //friends_paise[u]++;
    int s = g[u].size();
    int v;
    for(int w=0;w<s;w++)
    {
        v = g[u][w];
        if(color[v]==0)
        {
            friends_paise[v]++;
            dfs(v);
        }
    }
    color[u]=2;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        for(int w=0;w<maxn;w++)g[w].clear();
        memset(friends_paise,0,sizeof friends_paise);
        scanf("%d%d%d",&k,&n,&m);
        for(int w=0;w<k;w++)
        {
            scanf("%d",&friends[w]);
            friends_paise[friends[w]]++;
        }
        for(int w=0;w<m;w++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
           // g[y].push_back(x);
        }
        for(int w=0;w<k;w++)
        {
            memset(color,0,sizeof color);
            dfs(friends[w]);
        }
        int j = 0;
        for(int w=1;w<=n;w++)
        {
            if(friends_paise[w]>= k)j++;
        }
        printf("Case %d: %d\n",test,j);


    }
    return 0;
}
