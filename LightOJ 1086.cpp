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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,x,y,c,d;
int cost[17][17];
int degree[17];
ll memo[32769];
vector<int> pair_nodes;
ll dp(int mask)
{
  if((1<<d)-1 == mask)return 0;
  if(memo[mask]!=-1)return memo[mask];
  ll p = INT_MAX;
  vector<int>tempo;
  for(int i=0;i<d;i++)
  {
    if(!check(mask,i))
    {
      tempo.pb(i);
    }
  }
  for(int q=0;q<(int)tempo.sz;q++)
  {
    for(int w=q+1;w<(int)tempo.sz;w++)
    {
      int task = mask;
      task = Set(task,tempo[q]);
      task = Set(task,tempo[w]);
      p = min (p, cost[pair_nodes[tempo[q]]][pair_nodes[tempo[w]]]+dp(task));
    }
  }
  memo[mask]=p;
  return p;
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  memset(degree,0,sizeof degree);
  memset(memo,-1,sizeof memo);
  pair_nodes.clear();
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cost[i][j]=INT_MAX;
    }
  }
  ll fin = 0;
  for(int i=0;i<m;i++)
  {
    scanf("%d%d%d",&x,&y,&c);

    degree[x]++;
    degree[y]++;
    cost[x][y] = min(cost[x][y],c);
    cost[y][x] = min(cost[y][x],c);
    fin+=c;
  }


  for(int i=1;i<=n;i++)
  {
    if(degree[i]%2==1)pair_nodes.pb(i);
  }
  d=pair_nodes.sz;
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(cost[i][k]!= INT_MAX && cost[k][j] != INT_MAX)
        {
          cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
        }
      }
    }
  }

  fin+=dp(0);
  printf("Case %d: %lld\n",test,fin);

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
