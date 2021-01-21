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
#define maxn 20005
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
int m,n,row,col,x,y,ans,fn;
vector<int>g[maxn],gt[maxn],cg[maxn],cgt[maxn];
int color[maxn];
int visited[maxn];
int par[maxn];
int parent[maxn];
int total_compressed_nodes;
stack <int> dfsStack,cStack;
queue <int> sccQueue;
bool sex = 0;
void dfs(int u)
{
  color[u]=1;
  for(auto v : g[u])
  {
    if(color[v]==0)dfs(v);
  }
  color[u]=2;
  dfsStack.push(u);
}
void dfsTranspose(int u,int i)
{
  visited[u]=1;
  par[u]=i;

  sccQueue.push(u);
  for(auto v : gt[u])
  {
    if(visited[v]==0)
    {
      dfsTranspose(v,i);
    }
  }
}
void findSCC()
{
  fill(color,color+n+1,0);
  while(!dfsStack.empty())dfsStack.pop();
  while(!sccQueue.empty())sccQueue.pop();
  fill(par,par+n+1,-1);
  for(int i=1;i<=n;i++)
  {
    if(color[i]==0)
    {
      dfs(i);
    }
  }
  int comp = 0;
  int u;
  fill(visited,visited+n+1,0);
  while(!dfsStack.empty())
  {
    u = dfsStack.top();
    dfsStack.pop();
    if(visited[u]==0)
    {
      dfsTranspose(u,comp);
      comp++;
    }
  }
  total_compressed_nodes = comp;
}
void compress()
{
  int u;
  fill(parent,parent+n+1,-1);

  while(!sccQueue.empty())
  {
    u = sccQueue.front();
    sccQueue.pop();
    for(auto v : g[u])
    {
      if(par[v] != par[u] && parent[par[v]]!=par[u])
      {
        parent[par[v]]=par[u];
        cg[par[u]].pb(par[v]);
        cgt[par[v]].pb(par[u]);
      }
    }
  }

}
void findRoad()
{
  int ind=0,out=0;
  for(int i=0;i<total_compressed_nodes;i++)
  {
    if((int)cg[i].sz == 0)out++;
    if((int)cgt[i].sz == 0)ind++;
  }
  ans = max(out,ind);
  if(total_compressed_nodes==1)ans=0;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    gt[y].pb(x);
  }
  findSCC();
  compress();
  ans=0;
  findRoad();

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
      gt[i].clear();
      cg[i].clear();
      cgt[i].clear();
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
