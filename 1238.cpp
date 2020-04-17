#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
bool grid[25][25];
int t,row,col;
int ax,ay,bx,by,cx,cy,hx,hy;
string g;
int bfs(pii u,map<pii,int> level,map <pii,int> visited,pii d)
{
    //memset(visited,0,sizeof visited);
    level[u]=0;
    queue <pii> q;
    visited[u]=1;
    pii a;
    q.push(u);
    while(!q.empty())
    {
        a = q.front();
        q.pop();
        if(a.first + 1 < row && grid[a.first+1][a.second]==1 && visited[pii(a.first+1,a.second)]==0)
        {
            level[pii(a.first+1,a.second)] = level[a] + 1;
            visited[pii(a.first+1,a.second)] = 1;
            q.push(pii(a.first+1,a.second));
        }
        if(a.first - 1 >=0 && grid[a.first-1][a.second]==1 && visited[pii(a.first-1,a.second)]==0)
        {
            level[pii(a.first-1,a.second)] = level[a] + 1;
            visited[pii(a.first-1,a.second)] = 1;
            q.push(pii(a.first-1,a.second));
        }
        if(a.second + 1 < col && grid[a.first][a.second+1]==1 && visited[pii(a.first,a.second+1)]==0)
        {
            level[pii(a.first,a.second+1)] = level[a] + 1;
            visited[pii(a.first,a.second+1)] = 1;
            q.push(pii(a.first,a.second+1));
        }
        if(a.second - 1 >=0 && grid[a.first][a.second-1]==1 && visited[pii(a.first,a.second-1)]==0)
        {
            level[pii(a.first,a.second-1)] = level[a] + 1;
            visited[pii(a.first,a.second-1)] = 1;
            q.push(pii(a.first,a.second-1));
        }
    }
    return level[d];
}
int main()
{

    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&row,&col);
        for(int w=0;w<row;w++)
        {
            cin >> g;
            for(int q=0;q<g.size();q++)
            {
                if(g[q] == '.' ||  g[q] == 'a' || g[q] == 'b' || g[q] == 'c' || g[q] == 'h')grid[w][q]=1;
                else grid[w][q] = 0;

                if(g[q] == 'a')
                {
                    ax = w;
                    ay = q;
                }
                else if(g[q]=='b')
                {
                    bx = w;
                    by = q;
                }
                else if(g[q]=='c')
                {
                    cx = w;
                    cy = q;
                }
                else if(g[q]=='h')
                {
                    hx = w;
                    hy = q;
                }
            }
        }
        map <pii,int> j,k,l;
        map <pii,int> va,vb,vc;
        int ans1 = bfs(pii(ax,ay),j,va,pii(hx,hy));
        int ans2 = bfs(pii(bx,by),k,vb,pii(hx,hy));
        int ans3 = bfs(pii(cx,cy),l,vc,pii(hx,hy));
        printf("Case %d: %d\n",test,max(ans1,max(ans2,ans3)));
    }
    return 0;
}
