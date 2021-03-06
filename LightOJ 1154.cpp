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
#define sz size()
#define maxn 100000
#define eps 1e-9
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y,cost,ans,s,d,z;
double D;
int g[201][201];
int rg[201][201];
struct inc
{
  double x,y;
  int n,m;
}penguin[201];

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void reset()
    {
      edges.clear();
      for(int i=0;i<205;i++)adj.clear();
      adj.resize(n);
      level.resize(n);
      ptr.resize(n);
      m=0;
    }
    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            //trace(adj[v].sz)
            for (int id : adj[v]) {
              //trace(edges[id].u)
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
            {
                break;
            }
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
Dinic dinic = Dinic(205,0,0);
double dist(int u,int v)
{
  return (penguin[u].x-penguin[v].x)*(penguin[u].x-penguin[v].x) + (penguin[u].y-penguin[v].y)*(penguin[u].y-penguin[v].y);
}
void build_graph()
{
  //1 to N are entry
  //N+1 to N+N are exit
  //0 is source
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==j)continue;
      if(lessThan(dist(i,j),D*D))
      {
        dinic.add_edge(i+1+n,j+1,INT_MAX);
      }
    }
  }
  for(int i=1;i<=n;i++)
  {
    dinic.add_edge(i,i+n,penguin[i-1].m);
    dinic.add_edge(0,i,penguin[i-1].n);
  }


}
void solve(int test)
{
  scanf("%d%lf",&n,&D);
  row=0;
  vector<int>ans;
  for(int i=0;i<n;i++)
  {
    scanf("%lf%lf%d%d",&penguin[i].x,&penguin[i].y,&penguin[i].n,&penguin[i].m);
    row+=penguin[i].n;
  }

  for(int i=0;i<n;i++)
  {
      dinic.reset();
      build_graph();
      dinic.s = 0;
      dinic.t = i+1;
      ll bruh = dinic.flow();
      //trace(bruh)
      if(bruh==row)ans.pb(i);
  }
  //printing
  if((int)ans.size() == 0)printf("Case %d: -1\n",test);
  else
  {
    printf("Case %d: ",test);
    bool s = 0;
    for(auto x : ans)
    {
      if(s)printf(" ");
      s=1;
      printf("%d",x);
    }
    printf("\n");
  }
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve( test);
  }
}
int main()
{
  test();
  return 0;
}
