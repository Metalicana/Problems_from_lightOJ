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
int m,n,row,col,x,y;
const int WHITE = 0;
const int BLACK = 1;
int color[1005];
vector <int> g[1005];
int dp1[1005];
int tap[1005];
int dp2[1005];
//dp1 is number of black nodes if I paint myself BLACK
//dp2 is number of black node if I paint myself WHITE
void dfs(int  V,int pV)
{
  tap[V]=1;
  int a=1,b=0;
  for(auto v : g[V])
  {
    if(v == pV)continue;
    if(color[pV] == WHITE || pV == 0)
    {
      color[V] = BLACK;
      if(dp2[v]==-1)dfs(v,V);
      a += dp2[v];
      color[V] = WHITE;
      if(dp1[v]==-1 || dp2[v])dfs(v,V);
      b += max(dp1[v],dp2[v]);
    }
    else
    {
      color[V] = WHITE;
      if(dp1[v] == -1 || dp2[v] == -1)dfs(v,V);
      b += max(dp1[v],dp2[v]);
    }
  }
  dp1[V] = a;
  dp2[V] = b;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  for(int w=0;w<m;w++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  memset(dp1,-1,sizeof dp1);
  memset(dp2,-1,sizeof dp2);
  memset(tap,-1,sizeof tap);
  int ans = 0;
  for(int q=1;q<=n;q++)
  {
    if(tap[q] == -1)
    {
      dfs(q,0);
      ans += max(dp1[q],dp2[q]);
    }
  }

  printf("Case %d: %d\n",test,ans);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int w=0;w<1005;w++)g[w].clear();
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
