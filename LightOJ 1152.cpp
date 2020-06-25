#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 420
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,nodeNumber;
char graph[maxn][maxn];
int  node[maxn][maxn];
bool valid(int x,int y)
{
  return x>=0&&x<row&&y>=0&&y<col;
}
const int sz = 205, INF = INT_MAX;


// root(V) * E
struct hop {
   int pu[sz], pv[sz], dist[sz];
   vector <int> g[sz];
   queue <int> q;

   void addEdge(int u, int v) {
      g[u].push_back(v);
   }

   bool bfs(int n) {
      dist[0] = INF;
      for(int i=1; i<=n; i++) {
         if(!pu[i]) dist[i] = 0, q.push(i);
         else dist[i] = INF;
      }

      while(!q.empty()) {
         int u = q.front(); q.pop();
         if(dist[u] < dist[0]) {
            for(int v : g[u]) {
               int nu = pv[v];
               if(dist[nu] == INF) {
                  dist[nu] = dist[u] + 1;
                  if(nu) q.push(nu);
               }
            }
         }
      }
      return dist[0] ^ INF;
   }

   bool dfs(int u) {
      if(!u) return 1;
      for(int v : g[u]) {
         int nu = pv[v];
         if(dist[nu] == dist[u] + 1 && dfs(nu)) {
            pv[v] = u;
            pu[u] = v;
            return 1;
         }
      }
      dist[u] = INF;
      return 0;
   }

   int hopcroft(int n, int m = 0) {
      int ans = 0;
      memset(pu, 0, sizeof pu);  // nodes of l.h.s (n)
      memset(pv, 0, sizeof pv);  // nodes of r.h.s (m)

      while(bfs(n)) {
         for(int i=1; i<=n; i++) {
            if(!pu[i] && dfs(i)) {
               ans++;
            }
         }
      }
      return ans;
   }
};


void solve(int test)
{
  int i,j,k,d,x,y;
  n=0,m=0;
  scanf("%d%d",&row,&col);
  rep(i,row)scanf("%s",graph[i]);
  rep(i,row)rep(j,col)
  {
    if(graph[i][j] == '*' && (i+j)&1)node[i][j]=++n;
    else node[i][j]=0;
  }
  hop carp;
  rep(i,row)rep(j,col)
  {
    if(graph[i][j]=='*' && node[i][j]==0)
    {
      m++;
      rep(k,4)
      {
        x = i+dir4[0][k];
        y = j+dir4[1][k];
        if(valid(x,y))
        {
          if(graph[x][y]=='*')
          {
            carp.addEdge(m,node[x][y]);
          }
        }
      }

    }
  }
  int ans = m+n-carp.hopcroft(m);

  printf("Case %d: %d\n",test,ans);
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
