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
#define maxn 50005
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
vector<int> g[maxn],gt[maxn],c[maxn];
int vis[maxn];
int par[maxn];
int D[maxn];
stack <int> dfsStack;
int sexvideo[maxn];
int nodeCountInComponent[maxn];
void dfs1(int u)
{
  vis[u]=1;
  for(auto v : g[u])
  {
    if(vis[v]==0)dfs1(v);
  }

  dfsStack.push(u);
}
void dfs2(int u,int cmp)
{
  nodeCountInComponent[cmp]++;
  par[u]=cmp;
  sexvideo[cmp]=min(sexvideo[cmp],u+1);
  vis[u]=1;
  for(auto v: gt[u])
  {
    if(vis[v]==0)dfs2(v,cmp);
  }
}

int findSCC()
{
  fill(vis,vis+n,0);
  for(int i=0;i<n;i++)
  {
    if(vis[i]==0)dfs1(i);
  }

  fill(nodeCountInComponent,nodeCountInComponent+n,0);
  fill(vis,vis+n,0);
  int cmp = 0;
  int u;
  while(!dfsStack.empty())
  {
    u = dfsStack.top();
    dfsStack.pop();
    if(vis[u]==0)
    {
      dfs2(u,cmp);
      cmp++;
    }
  }
  return cmp;
}
void dfs(int u)
{
  vis[u]=1;
  int d = nodeCountInComponent[u];
  for(auto v: c[u])
  {
    if(vis[v]==2)
    {
      d += D[v];
    }
    else if(vis[v]==0)
    {
      dfs(v);
      d+=D[v];
    }
  }
  D[u]=d;
  vis[u]=2;
}
void sexDFS(int u)
{
  vis[u]=1;
  for(auto v: c[u])
  {
    if(vis[v]==0)sexDFS(v);
  }

  dfsStack.push(u);
}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d",&x,&y);
    g[x-1].pb(y-1);
    gt[y-1].pb(x-1);
  }
  fill(sexvideo,sexvideo+n,100000000);
  while(!dfsStack.empty())dfsStack.pop();
  int cmp = findSCC();
  int u,v;
  for(int i=0;i<n;i++)
  {
    u = i;
    for(auto v : g[u])
    {
      if(par[u]!=par[v])
      {
        c[par[u]].pb(par[v]);
      }
    }
  }

  fill(D,D+cmp,0);
  fill(vis,vis+cmp,0);
  while(!dfsStack.empty())dfsStack.empty();
  for(int i=0;i<cmp;i++)
  {
    if(vis[i]==0)sexDFS(i);
  }
  fill(vis,vis+cmp,0);
  while(!dfsStack.empty())
  {
    u = dfsStack.top();
    dfsStack.pop();
    if(vis[u]==0)dfs(u);
  }
  int ans = 0;
  int ass=2000000000;
  for(int i=0;i < cmp; i++)
  {
    if(D[i] > ans)
    {
      ans = D[i];
      ass = sexvideo[i];
    }
    else if(D[i]==ans)
    {
      ass = min(ass, sexvideo[i]);
    }
  }
  printf("Case %d: %d\n",test,ass);

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
      gt[i].clear();
      c[i].clear();
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
