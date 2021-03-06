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
#define eps 1e-9
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}
template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,MOD-2);
}

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

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE

int m,n,row,col,u,v;
int timePassed;
int low[maxn+1];
int vis[maxn+1];
int d[maxn+1];
int cnt,oddc;

vector<int>g[maxn];
set<int>f[maxn];

void dfs(int u,int parent)
{
  timePassed++;
  vis[u]=1;
  d[u]=low[u]=timePassed;

  for(auto v: g[u])
  {
    if(v == parent)continue;
    if(vis[v]==1)
    {
      low[u] = min(low[u],d[v]);
    }
    else if(vis[v]==0)
    {
      dfs(v,u);
      low[u]=min(low[u],low[v]);
      if(d[u] < low[v] )
      {
        f[u].erase(v);
        f[v].erase(u);
      }
    }
  }
}
void findArticulationBridges()
{
  timePassed = 0;//setting the clock


  fill(vis,vis+n+1,0);
  fill(low,low+n+1,INT_MAX);

  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      dfs(i,-1);
    }
  }

}
void dfs2(int u,int p,int len)
{
  d[u]=len;
  vis[u]=1;
  cnt++;
  for(auto v : f[u])
  {
    if(v==p)continue;
    if(!vis[v])
    {
      dfs2(v,u,len+1);
    }
    else if(vis[v]==1 && (d[v]-d[u])%2 == 0)
    {
      oddc = 1;
    }
  }
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d%d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
    f[u].insert(v);
    f[v].insert(u);
  }
  findArticulationBridges();
  fill(vis,vis+n,0);
  int ans = 0;
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
      cnt=0;
      oddc=0;
      dfs2(i,-1,0);
      if(oddc)ans+=cnt;
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
    for(int i=0;i<maxn;i++)
    {
      g[i].clear();
      f[i].clear();
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
