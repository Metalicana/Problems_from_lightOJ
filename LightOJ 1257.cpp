#include <bits/stdc++.h>
using namespace std;
vector <int> g[30005];
vector <int> p[30005];
int n,x,y,c;
int bfs1(int u)
{
    bool visited[30005];
    int level[30005];
    memset(visited,0,sizeof visited);
    memset(level,0,sizeof level);
    visited[u]=1;
    queue <int> q;
    q.push(u);
    int v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int w=0;w<g[u].size();w++)
        {
            v = g[u][w];
            if(!visited[v])
            {
                level[v] = level[u] + p[u][w];
                visited[v]=1;
                q.push(v);
            }
        }
    }
    int ans_node,maxii=0;
    for(int w=0;w<n;w++)
    {
        if(level[w] >= maxii)
        {

            maxii = level[w];
            ans_node = w;
        }
    }
    return ans_node;
}
void bfs2(int u)
{
    bool visited[30005];
    bool visited2[30005];
    int level[30005];
    int level2[30005];
    memset(visited,0,sizeof visited);
    memset(visited2,0,sizeof visited2);
    memset(level,0,sizeof level);
    memset(level2,0,sizeof level2);
    visited[u]=1;
    queue <int> q;
    q.push(u);
    int v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int w=0;w<g[u].size();w++)
        {
            v = g[u][w];
            if(!visited[v])
            {
                level[v] = level[u] + p[u][w];
                visited[v]=1;
                q.push(v);
            }
        }
    }
    int maxii=0,ans_node;
    for(int w=0;w<n;w++)
    {
        if(level[w] > maxii)
        {

            maxii = level[w];
            ans_node = w;
        }
    }
    u = ans_node;
    visited2[u]=1;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int w=0;w<g[u].size();w++)
        {
            v = g[u][w];
            if(!visited2[v])
            {
                level2[v] = level2[u] + p[u][w];
                visited2[v]=1;
                q.push(v);
            }
        }
    }
    for(int w=0;w<n;w++)
    {
        printf("%d\n", max(level[w],level2[w]));
    }
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        for(int w=0;w<30005;w++)g[w].clear();
        for(int w=0;w<30005;w++)p[w].clear();
        scanf("%d",&n);
        for(int w=0;w<n-1;w++)
        {
            scanf("%d%d%d",&x,&y,&c);
            g[x].push_back(y);
            g[y].push_back(x);
            p[x].push_back(c);
            p[y].push_back(c);
        }
        int start = bfs1(0);
        printf("Case %d:\n",test);
        bfs2(start);
    }
    return 0;
}
