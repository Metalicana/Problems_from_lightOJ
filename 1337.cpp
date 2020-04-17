#include <bits/stdc++.h>
using namespace std;
#define maxn 505
int m,n,q,p,x,y,c;
int par[maxn][maxn];
char grid[maxn][maxn];
bool vis[maxn][maxn];
int money[maxn];
char s[maxn];
void bfs(int x,int y,int p)
{
    vis[x][y] = 1;
    par[x][y] = p;
    if(grid[x][y] == 'C')c++;
    queue <pair <int,int> > q;
    q.push(make_pair(x,y));
    pair <int,int> u;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        if(u.second+1 < n && !vis[u.first][u.second+1] && grid[u.first][u.second+1] != '#')
        {
            par[u.first][u.second+1] = p;
            vis[u.first][u.second+1] = 1;
            if(grid[u.first][u.second+1] == 'C')c++;
            q.push(make_pair(u.first,u.second+1));
        }
        if(u.second-1 >= 0 && !vis[u.first][u.second-1] && grid[u.first][u.second-1] != '#')
        {
            par[u.first][u.second-1] = p;
            vis[u.first][u.second-1] = 1;
            if(grid[u.first][u.second-1] == 'C')c++;
            q.push(make_pair(u.first,u.second-1));
        }
        if(u.first+1 < m && !vis[u.first+1][u.second] && grid[u.first+1][u.second] != '#')
        {
            par[u.first+1][u.second] = p;
            vis[u.first+1][u.second] = 1;
            if(grid[u.first+1][u.second] == 'C')c++;
            q.push(make_pair(u.first+1,u.second));
        }
        if(u.first-1 >= 0 && !vis[u.first-1][u.second] && grid[u.first-1][u.second] != '#')
        {
            par[u.first-1][u.second] = p;
            vis[u.first-1][u.second] = 1;
            if(grid[u.first-1][u.second] == 'C')c++;
            q.push(make_pair(u.first-1,u.second));
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
        memset(vis,0,sizeof vis);
        memset(money,0,sizeof money);
        memset(par,0,sizeof par);
        scanf("%d%d%d",&m,&n,&q);
        for(int w=0; w<m; w++)
        {
            scanf("%s",s);
            for(int q=0; q<n; q++)
            {
                grid[w][q] = s[q];
            }
        }
        p=1;
        for(int w=0; w<m; w++)
        {
            for(int q=0; q<n; q++)
            {
                if(!vis[w][q] && grid[w][q] != '#')
                {
                    c=0;
                    bfs(w,q,p);
                    money[p] = c;
                    p++;
                }
            }
        }
        printf("Case %d:\n",test);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            printf("%d\n",money[par[x][y]]);
        }
    }

    return 0;
}
