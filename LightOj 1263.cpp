#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y,req;
vector<int> g[1006];
int cost[1006];
int vis[1006];
bool bfs(int u)
{
  vis[u] = 1;
  queue<int> q;
  q.push(u);
  int c = cost[u];
  int node = 1;
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(auto v : g[u])
    {
      if(!vis[v])
      {
        node++;
        c += cost[v];
        vis[v] = 1;
        q.push(v);;
      }
    }
  }
  //trace2(c,node)
  if(c/node != req )return 0;
  return 1;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  int sum = 0;
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&cost[i]);
    sum += cost[i];
  }
  for(int w=0;w<m;w++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  if(sum%n != 0)printf("Case %d: No\n",test);
  else
  {
    memset(vis,0,sizeof vis);
    req = sum/n;

    int ass = 0;
    for(int w=1;w<=n;w++)
    {
      if(!vis[w])
      {
        if(!bfs(w))ass=1;
      }
    }
    if(!ass)printf("Case %d: Yes\n",test);
    else printf("Case %d: No\n",test);
  }
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int w=0;w<1006;w++)g[w].clear();
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
