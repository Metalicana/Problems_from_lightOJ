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
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll add(ll a , ll b)
{
  if(a + b < mod)return a+b;
  return (a+b)%mod;
}
ll mul(ll a, ll b)
{
  if(a*b < mod)return a*b;
  return (a*b)%mod;
}
ll power(ll b,ll p)
{
  if(p == 0)return 1;
  if(p == 1)return b;
  ll j = power(b,p/2);
  j = mul(j,j);
  if(p%2==0)return j;
  return mul(b,j);
}
int m,n,row,col,x,y;
vector <int> g[1005];
vector <int> h[1005];
ll dp[1005];
ll fact[1005],invFact[1005],child[1005];
void dfs(int V)
{
  ll cnt = 1;
  ll ch = 0;
  for(auto v:g[V])
  {
    dfs(v);
    ch+=child[v];
    cnt = mul(cnt,dp[v]);
    cnt = mul(cnt,invFact[child[v]]);
  }
  child[V] = 1 + ch;

  cnt = mul(cnt,fact[child[V]-1]);
  dp[V] = cnt;
  //trace2(V,dp[V])
}
void solve(int test)
{
  scanf("%d",&n);
  for(int w=1;w<n;w++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    h[y].pb(x);
  }
  for(int i=1;i<=n;i++)
  {
    if(h[i].sz == 0)
    {
      dfs(i);
      printf("Case %d: %lld\n",test,dp[i]);
    }
  }
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(child,0,sizeof child);
    for(int w=0;w<1005;w++)g[w].clear(),h[w].clear();
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  fact[0] = 1, invFact[0] = 1;
  for(int i=1;i<1005;i++)
  {
    fact[i] = mul(i , fact[i-1]);
    invFact[i] = power(fact[i],mod-2);
  }
  test();
  return 0;
}
