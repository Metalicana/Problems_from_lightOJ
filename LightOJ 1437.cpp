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
vector<int>g[505];
int dist[505];
int cycle;
int bfs(int u)
{
  queue<int>q;
  dist[u]=0;
  q.push(u);
  int ans = INT_MAX;
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(auto v: g[u])
    {
      if(v!=u)
      {
        if(dist[v]!=INT_MAX && dist[v] >= dist[u])
        {
          //cycles
          ans = min(ans,dist[v]+dist[u]+1 );
        }
        else if(dist[v]==INT_MAX)
        {
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
    }
  }
  return ans;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  for(int i=0;i<505;i++)g[i].clear();

  cycle = INT_MAX;
  for(int i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  for(int i=0;i<n;i++)
  {
    fill(dist,dist+n,INT_MAX);
    cycle = min(cycle,bfs(i));
  }
  if(cycle == INT_MAX)printf("Case %d: impossible\n",test);
  else printf("Case %d: %d\n",test,cycle);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
