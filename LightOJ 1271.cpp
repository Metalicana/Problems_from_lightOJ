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
int nodes[50006];
int nodes2[50006];
int mapping[50006];
int reverse_mapping[50006];
vector<int>g[50006];
int dist[50006];
int vis[50006];
int parent[50006];
void solve(int test)
{
  for(int i=0;i<50006;i++)g[i].clear();
  scanf("%d",&n);

  int source,dest;
  for(int i=0;i<n;i++)
  {
    scanf("%d",&nodes[i]);
    nodes2[i]=nodes[i];
  }
  sort(nodes,nodes+n);
  int d = 0;
  for(int i=0;i<n;i++)
  {
    mapping[nodes[i]]=d;
    reverse_mapping[d] = nodes[i];
    d++;
  }
  source = mapping[nodes2[0]];
  dest = mapping[nodes2[d-1]];
  for(int i=0;i<d-1;i++)
  {
    g[mapping[nodes2[i]]].pb(mapping[nodes2[i+1]]);
    g[mapping[nodes2[i+1]]].pb(mapping[nodes2[i]]);
  }
  //from 1 to d, we have this graph
  fill(vis,vis+d,0);
  fill(dist,dist+d,INT_MAX);
  queue <int> q;
  q.push(dest);
  int u;
  vis[dest]=1;
  dist[dest]=0;
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(auto v : g[u])
    {
      if(!vis[v])
      {
        parent[v]=u;
        dist[v]=dist[u]+1;
        vis[v]=1;
        q.push(v);
      }
      else
      {
        if(dist[v] == dist[u]+1)
        {
          parent[v] = min(parent[v],u);
        }
      }
    }
  }
  printf("Case %d:\n",test);
  for(int i=source;;)
  {
    printf("%d",reverse_mapping[i]);
    if(i == dest)break;
    else printf(" ");
    i = parent[i];
  }
  printf("\n");


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
