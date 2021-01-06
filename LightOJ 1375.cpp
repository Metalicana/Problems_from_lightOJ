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
vector<int>g[100005],p[100005];
bool vis[100005];
int c[100005];
ll grand_total;
void dfs(int v,int pv)
{
  vis[v]=1;
  int children = 0;
  for(auto V : g[v])
  {
    if(!vis[V])
    {
      dfs(V,v);
      children += (c[V]+1);
      p[v].pb(c[V]+1);
    }
  }
  ll sum = 0;
  ll totes = 0;
  for(int i=0;i<p[v].sz;i++)
  {
    sum += p[v][i];
  }
  for(int i=0;i<p[v].sz;i++)
  {
    sum -= p[v][i];
    totes += p[v][i]*sum;
  }
  grand_total+=totes;
  c[v]=children;

}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=1;i<n;i++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  grand_total=0;
  dfs(1,0);
  printf("Case %d: %d %lld\n",test,n-1,grand_total);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int i=0;i<100005;i++)
    {
      g[i].clear();
      p[i].clear();
    }
    memset(vis,0,sizeof vis);
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
/*
13
1 2
1 3
3 6
3 7
2 4
2 5
4 8
5 9
5 10
9 11
11 12
11 13
*/
