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
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}
ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y;
vector<int> g[18];
int dp[(1<<15)+15];
int vis[16][(1<<15)+15];
void dfs(int i,int mask)//for dp
{
  dp[mask]=1;
  vis[i][mask]=1;
  for(auto v : g[i])
  {
    if(vis[v][Set(mask,v)]==0)dfs(v,Set(mask,v));
  }
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  fill(dp,dp+(1<<n)+10,69);
  for(int i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    g[x-1].pb(y-1);
  }
  memset(vis,0,sizeof vis);
  for(int i=0;i<n;i++)
  {
    dfs(i,Set(0,i));
  }
  for(int i=0; i < (1<<n); i++)
  {
    x = i;
    while(x > 0)
    {
      dp[i] = min(dp[i],dp[x]+dp[i^x]);
      x = (x-1)&i;
    }
  }
  printf("Case %d: %d\n",test,dp[(1<<n)-1]);

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int i=0;i<18;i++)
    {
      g[i].clear();
    }
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
