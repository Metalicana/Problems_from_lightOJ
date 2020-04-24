#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int mod(int x,int y)
{
  int s;
  s = abs(x)/y;
  if(x<0)s--;
  return x-y*s;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y,cost,ans,s,d;
int g[101][101];
int rg[101][101];
bool bfs(int s,int d,int parent[])
{
  parent[s] = -1;
  int visited[n+1];
  memset(visited,0,sizeof visited);
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while(!q.empty())
  {
    s = q.front();
    q.pop();
    for(int w=1;w<=n;w++)
    {
      if(visited[w] == false && rg[s][w] > 0 )
      {
        q.push(w);
        parent[w] = s;
        visited[w] = 1;
      }
    }
  }
  return visited[d]==1;
}
int ford(int s,int d)
{
  int parent[n+1];
  int maxFlow = 0;
  int u;
  while(bfs(s,d,parent))
  {
    int pathFlow = INT_MAX;
    for(int q=d;q!=s;q = parent[q])
    {
      u = parent[q];
      pathFlow = min(pathFlow,rg[u][q]);
    }
    for(int q=d;q!=s;q = parent[q])
    {
      u = parent[q];
      pathFlow = min(pathFlow,rg[u][q]);
      rg[u][q] -= pathFlow;
      rg[q][u] += pathFlow;
    }
    maxFlow += pathFlow;
  }
  return maxFlow;

}
void solve(int test)
{
  scanf("%d%d%d%d",&n,&s,&d,&m);
  while(m--)
  {
    scanf("%d%d%d",&x,&y,&cost);
    g[x][y] += cost;
    g[y][x] += cost;
    rg[x][y] += cost;
    rg[y][x] += cost;
  }

  ans = ford(s,d);
  printf("Case %d: %d\n",test,ans);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(g,0,sizeof g);
    memset(rg,0,sizeof rg);
    solve( test);
  }
}
int main()
{
  test();
  return 0;
}
