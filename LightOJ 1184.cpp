#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
int height,age,single;
struct human
{
  int h,a,s;
};
int g[202][202];
int rg[210][210];
bool bfs(int s,int d,int parent[])
{
  parent[s] = -1;
  int visited[n+2+m+4];
  memset(visited,0,sizeof visited);
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while(!q.empty())
  {
    s = q.front();
    q.pop();
    for(int w=1;w<=n+m+2;w++)
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
  int parent[n+m+2+4];
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
human men[55],women[55];
bool compatible(human man, human woman)
{
  if(man.s== woman.s)
  {
    if(abs(man.h - woman.h) <= 12)
    {
      if(abs(woman.a-man.a) <= 5)return 1;
      return 0;
    }
    return 0;
  }
  return 0;
}
void solve(int test)
{
  memset(rg,0,sizeof rg);
  scanf("%d%d",&m,&n);
  for(int w=0;w<m;w++)
  {
    scanf("%d%d%d",&height,&age,&single);
    men[w].h = height,men[w].a=age,men[w].s=single;
  }
  for(int w=0;w<n;w++)
  {
    scanf("%d%d%d",&height,&age,&single);
    women[w].h = height,women[w].a=age,women[w].s=single;
  }
  //men starts with 1
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(compatible(men[i],women[j]))
      {
        rg[i+2][m+j+2]=1;
      }
    }
  }
  for(int i=0;i<m;i++)rg[1][i+2]=1;
  for(int i=m;i<m+n;i++)rg[i+2][m+n+2]=1;
  int ans = ford(1,m+n+2);
  printf("Case %d: %d\n",test,ans);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
