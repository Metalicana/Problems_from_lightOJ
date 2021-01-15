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
#define maxn 1005
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
vector <int> g[maxn],gt[maxn];
vector <int> cg[maxn];
int color[maxn];
int visited[maxn];
int par[maxn];
int total_compressed_nodes;
stack <int> dfsStack;
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
  for(auto v : gt[u])
  {
    if(visited[v]==0)
    {
      dfsTranspose(v,i);
    }
  }
}
bool findSCC()
{
  fill(color,color+maxn,0);
  while(!dfsStack.empty())dfsStack.pop();
  for(int i=0;i<maxn;i++)
  {
    if(color[i]==0 && (int)g[i].sz!=0)
    {
      if(i!=0)return 0;
      dfs(i);

    }
  }
  int comp = 0;
  int u;
  fill(visited,visited+maxn,0);
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
  return 1;
}
bool compress()
{
  for(int i=0;i<maxn;i++)
  {
    for(auto v : g[i])
    {
      if(par[i]!=par[v])//different component
      {
        cg[par[i]].pb(par[v]);
        if((int)cg[par[i]].sz>1)return 0;
      }
    }
  }
  fill(visited,visited+total_compressed_nodes,0);
  visited[0]=1;
  queue <int> q;
  q.push(0);
  int u;
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(auto v : cg[u])
    {
      if(!visited[v])
      {
        visited[v]=1;
        q.push(v);
      }
    }
  }
  for(int i=0;i<total_compressed_nodes;i++)
  {
    if(visited[i]==0)return 0;
  }
  return 1;
}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&m);
    while(m--)
    {
      scanf("%d%d",&x,&y);
      g[x].pb(y);
      gt[y].pb(x);
    }
  }
  if((int)g[0].sz==0)printf("Case %d: NO\n",test);
  else
  {
    fill(par,par+maxn,-1);//-1 means he is not part of any component :)
    if(findSCC())
    {
      if(compress())printf("Case %d: YES\n",test);
      else printf("Case %d: NO\n",test);
    }
    else printf("Case %d: NO\n",test);

  }

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
