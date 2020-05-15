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
#define maxn 100004
#define inf 100000000000000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,u,v,x,y,c,q;
vector <ll> g[maxn];
vector <ll> cost[maxn];
bool vis[maxn];
ll parent[maxn];
ll dist[maxn];
ll sparse[maxn][(ll)log2(maxn)+2];
ll cost_sparse[maxn][(ll)log2(maxn)+2];
ll cost_nunu[maxn][(ll)log2(maxn)+2];
ll depth[maxn];
void solve(int test)
{
  scanf("%lld",&n);
  for(int w=0;w < n-1; w++)
  {
    scanf("%lld%lld%lld",&u,&v,&c);
    g[u].pb(v);
    g[v].pb(u);
    cost[u].pb(c);
    cost[v].pb(c);
  }
  //root is 1
  memset(vis,0,sizeof vis);
  queue <ll > edgy;
  vis[1] = 1;
  dist[1] = 0;
  parent[1] = -1;
  depth[1] = 0;
  edgy.push(1);
  while(!edgy.empty())
  {
    x = edgy.front();
    edgy.pop();
    for(ll i = 0; i < (ll)g[x].size(); i++)
    {
      v = g[x][i];
      if(!vis[v])
      {
        vis[v] = 1;
        parent[v] = x;
        depth[v] = depth[x]+1;
        dist[v] = dist[x] + cost[x][i];
        cost_sparse[v][0] = cost[x][i];
        cost_nunu[v][0] = cost[x][i];
        edgy.push(v);
      }
    }
  }

  for(ll i=1;i<=n;i++)
  {
    sparse[i][0] = parent[i];
  }
  for(ll j = 1; (1 << j) < n; j++)
  {
    for(ll i = 1; i<= n; i++)
    {
      if(sparse[i][j-1]!=-1)
      {
        sparse[i][j] = sparse[sparse[i][j-1]][j-1];
        cost_sparse[i][j] = max(cost_sparse[i][j-1],cost_sparse[sparse[i][j-1]][j-1]);
        cost_nunu[i][j] = min(cost_nunu[i][j-1],cost_nunu[sparse[i][j-1]][j-1]);
      }
    }
  }
  scanf("%lld",&q);
  printf("Case %d:\n",test);
  while(q--)
  {
    scanf("%lld%lld",&x,&y);
    if(depth[x] < depth[y])swap(x,y);
    ll log  = 1;
    ll next;
    ll ans = 0;
    ll xc=0,yc=0;
    ll nunux = inf,  nunuy = inf;
    while(1)
    {
      next = log+1;
      if((1<<next)>depth[x])break;
      log++;
    }
    for(ll i = log; i>=0; i--)
    {
      if(depth[x] - (1 << i) >= depth[y])
      {
        xc = max(xc,cost_sparse[x][i]);
        nunux = min(nunux,cost_nunu[x][i]);
        x = sparse[x][i];
      }
    }
    if(x == y)printf("%lld %lld\n",nunux,xc);
    else
    {
      for (ll i = log; i >= 0; i--)
      {
        if (sparse[x][i] != -1 && sparse[x][i] != sparse[y][i])
        {
          xc = max(xc,cost_sparse[x][i]);
          nunux = min(nunux,cost_nunu[x][i]);
          nunuy = min(nunuy, cost_nunu[y][i]);
          yc = max(yc,cost_sparse[y][i]);
          x = sparse[x][i], y = sparse[y][i];
        }

      }
      xc = max(xc,cost_sparse[x][0]);
      yc = max(yc, cost_sparse[y][0]);
      nunux = min(nunux, cost_nunu[x][0]);
      nunuy = min(nunuy,cost_nunu[y][0]);
      printf("%lld %lld\n",min(nunux,nunuy),max(xc,yc));
    }


  }





}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int w=0;w<maxn;w++)
    {
      g[w].clear();
      cost[w].clear();

    }
    memset(sparse,-1,sizeof sparse);
    solve(test);
  }
}
int main()
{
  test();
  return 0;
}
