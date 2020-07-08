#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz 630
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define INF INT_MAX
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,sex;
char g[30][30];
int cost[626][626];
int vut_map[35][35],manush_map[35][35];
bool valid(int x,int y)
{
  return x>=0&&x<sex&&y>=0&&y<sex;
}

// root(V) * E
struct hop {
   int pu[sz], pv[sz], dist[sz];
   vector <int> g[sz];
   queue <int> q;

   void addEdge(int u, int v) {
      g[u].push_back(v);
   }

   bool bfs(int n,int rest) {
      dist[0] = INF;
      for(int i=1; i<=n; i++) {
         if(!pu[i]) dist[i] = 0, q.push(i);
         else dist[i] = INF;
      }

      while(!q.empty()) {
         int u = q.front(); q.pop();
         if(dist[u] < dist[0]) {
            for(int v : g[u]) {
               if(cost[u][v] <= rest)
               {
                 int nu = pv[v];
                 if(dist[nu] == INF) {
                    dist[nu] = dist[u] + 1;
                    if(nu) q.push(nu);
                 }
               }
            }
         }
      }
      return dist[0] ^ INF;
   }

   bool dfs(int u,int rest) {
      if(!u) return 1;
      for(int v : g[u]) {
         if(cost[u][v] <= rest)
         {
           int nu = pv[v];
           if(dist[nu] == dist[u] + 1  && dfs(nu,rest)) {
              pv[v] = u;
              pu[u] = v;
              return 1;
           }
         }
      }
      dist[u] = INF;
      return 0;
   }

   int hopcroft(int n,int rest) {
      int ans = 0;
      memset(pu, 0, sizeof pu);  // nodes of l.h.s (n)
      memset(pv, 0, sizeof pv);  // nodes of r.h.s (m)

      while(bfs(n,rest)) {
         for(int i=1; i<=n; i++) {
            if(!pu[i] && dfs(i,rest)) {
               ans++;
            }
         }
      }
      return ans;
   }
};
set <int> gosol;
vector<int> video;

void solve(int test)
{
  scanf("%d",&sex);
  int i,j,sx,sy;
  pii d;
  int vut = 0 , manush = 0;

  rep(i,sex)
  {
    scanf("%s",g[i]);
    rep(j,sex)
    {
      //trace2(i,j)
      if(g[i][j] == 'G')
      {
        vut_map[i][j] = ++vut;
      }
      else if(g[i][j] == 'H')
      {
        manush_map[i][j] = ++manush;
      }
    }
  }
  int vis[sex][sex]={0};
  int level[sex][sex];
  hop croft;
  int relations=0;
  queue <pii> q;
  gosol.clear(),video.clear();
  rep(i,sex)
  {
    rep(j,sex)
    {
      if(g[i][j] == 'G')
      {
        memset(vis,0,sizeof vis);
        vis[i][j]=1;
        level[i][j]=0;
        q.push(mp(i,j));
        while(!q.empty())
        {
          d = q.front();q.pop();
          for(int l=0;l<4;l++)
          {
            sx = d.x + dir4[0][l];
            sy = d.y + dir4[1][l];
            if(valid(sx,sy) && g[sx][sy] != '#' && vis[sx][sy]==0  )
            {
              vis[sx][sy]=1;
              level[sx][sy] = level[d.x][d.y] + 1;
              if(g[sx][sy] == 'H')
              {
                cost[vut_map[i][j]][manush_map[sx][sy]]=level[sx][sy];
                croft.addEdge(vut_map[i][j],manush_map[sx][sy]);
                gosol.insert(level[sx][sy]);
              }
              q.push(mp(sx,sy));
            }
          }
        }
      }
    }
  }
  //trace2(croft.hopcroft(vut,4),manush)
  for(auto khalu : gosol)video.pb(khalu);
  int ans;
  //binary search
  int left = 0;
  int right = video.size()-1;
  int mid;
  if(right == -1)printf("Case %d: Vuter Dol Kupokat\n",test);
  else
  {
    if(left == right)
    {
      ans = croft.hopcroft(vut,video[left]);
      if(ans == manush )printf("Case %d: %d\n",test,video[left]*2+2);
      else printf("Case %d: Vuter Dol Kupokat\n",test);
    }
    else
    {
      while(left < right)
      {
        mid = (left+right)/2;
        if(left+1==right)
        {
          ans = croft.hopcroft(vut,video[left]);
          if(ans == manush)
          {
            ans = left;
            break;
          }
          ans = croft.hopcroft(vut,video[right]);
          if(ans == manush)
          {
            ans = right;
            break;
          }

          ans = -1;
          break;
        }
        ans = croft.hopcroft(vut,video[mid]);
        if(ans == manush)right=mid;
        else left = mid;
      }
      if(ans == -1)printf("Case %d: Vuter Dol Kupokat\n",test);
      else
      {
        printf("Case %d: %d\n",test,video[ans]*2+2);
      }
    }
  }


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
