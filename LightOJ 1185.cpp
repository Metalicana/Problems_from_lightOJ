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
int m,n,row,col;
bool vis[2][105];
vector<int>g[105];
int x,y;
void bfs(int test)
{
  queue<pii> q;
  pii a,u;
  int s;
  a.x = 1;
  a.y = 0;//he carried her to this node
  //do not visit this as is, because this might corrupt the result.
  q.push(a);

  while(!q.empty())
  {
    u = q.front();
    q.pop();
    if(u.y == 0)s=1;
    else s = 0;
    for(auto v : g[u.x])
    {
      if(vis[s][v]==0)
      {
        q.push(mp(v,s));
        vis[s][v]=1;
      }
    }
  }
  int ans = 0;
  for(int i=1;i<=n;i++)
  {
    if(vis[0][i] == 1)ans++;
  }
  printf("Case %d: %d\n",test,ans);
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  memset(vis,0,sizeof vis);
  for(int i=0;i<105;i++)g[i].clear();
  for(int i=0;i<m;i++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  bfs(test);
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
