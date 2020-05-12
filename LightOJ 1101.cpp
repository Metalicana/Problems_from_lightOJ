#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 50005
#define mod 1000000007
#define inf 100000000000000
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

struct edge
{
  int u,v,w;
  bool operator<(const edge& p) const
  {
        return w < p.w;
  }
};
ll m,n,row,col,x,y,c,q;
ll parent[maxn];
ll pr[maxn];
ll sparse[maxn][(ll)log2(maxn)+2];
ll cost_sparse[maxn][(ll)log2(maxn)+2];
ll depth[maxn];
bool vis[maxn];
vector<edge> e;
map<pll, ll> cc;
vector <ll> g[maxn];
vector <ll> cost[maxn];
edge gett;
ll find(ll r)
{
    return pr[r]= (pr[r] == r) ? r : find(pr[r]);
}
void mst(ll n)
{
    sort(e.begin(), e.end());
    for (ll i = 1; i <= n; i++)
        pr[i] = i;

    ll count = 0, s = 0;
    for (ll i = 0; i < (ll)e.size(); i++) {
        ll u = find(e[i].u);
        ll v = find(e[i].v);
        if (u != v) {
            pr[u] = v;
            count++;
            g[e[i].u].pb(e[i].v);
            g[e[i].v].pb(e[i].u);
            cost[e[i].v].pb(e[i].w);
            cost[e[i].u].pb(e[i].w);
            if (count == n - 1)
                break;
        }
    }
}

void solve(int test)
{
  scanf("%lld%lld",&n,&m);
  for(int w=0;w<m;w++)
  {
    scanf("%lld%lld%lld",&x,&y,&c);
    gett.u = x;
    gett.v = y;
    gett.w = c;
    e.push_back(gett);
  }
  mst(n);
  queue <ll> edgy;
  memset(vis,0,sizeof vis);
  depth[1] = 0;
  edgy.push(1);
  vis[1] = 1;
  parent[1] = -1;
  ll v;
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
        cost_sparse[v][0] = cost[x][i];
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
        x = sparse[x][i];
      }
    }
    if(x == y)printf("%lld\n",xc);
    else
    {
      for (ll i = log; i >= 0; i--)
      {
        if (sparse[x][i] != -1 && sparse[x][i] != sparse[y][i])
        {
          xc = max(xc,cost_sparse[x][i]);
          yc = max(yc,cost_sparse[y][i]);
          x = sparse[x][i], y = sparse[y][i];
        }

      }
      xc = max(xc,cost_sparse[x][0]);
      yc = max(yc, cost_sparse[y][0]);
      printf("%lld\n",max(xc,yc));
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
      cost[w].clear();
      g[w].clear();
    }
    e.clear();
    memset(sparse,-1,sizeof sparse);
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
