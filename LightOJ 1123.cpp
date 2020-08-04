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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
struct edge
{
    int u,v,w;
    bool operator < (const edge& s) const
    {
        return w<s.w;
    }
};
vector <edge> cities;
int pr[205];
int findd(int x)
{
    if(pr[x] == x)return x;
    else return pr[x] = findd(pr[x]);
}

int mst(int n)
{
    for(int q=1; q<=n; q++)pr[q] = q;
    int s = 0;
    int cnt = 0;
    edge j;
    for(int q=0; q < (int)cities.size(); q++)
    {
        j = cities[q];
        int u = findd(j.u);
        int v = findd(j.v);
        if(u != v)
        {
            pr[u] = v;
            s += j.w;
            cnt++;
        }
        if(cnt >= n-1)break;
    }
    if(cnt != n-1)return -1;
    return s;
}
void solve(int test)
{
  int u,v,w,x;
  edge edgy;
  cities.clear();
  scanf("%d%d",&n,&m);
  printf("Case %d:\n",test);
  int s  =0;
  for(int i=0;i<m;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    //add this edge.
    edgy.u = u;
    edgy.v = v;
    edgy.w = w;

    if(s == 0)
    {
      cities.pb(edgy);
      s=1;
    }
    else
    {
      int jj = -1;
      for(int i=0;i<(int)cities.sz;i++)
      {
        if(cities[i].w > w)
        {
          jj = i;
          break;
        }
      }

      if(jj == -1)cities.pb(edgy);
      else cities.insert(cities.begin()+jj,edgy);
    }

    if(i < n-2)
    {
      printf("-1\n");
      continue;
    }
    else
    {
      x = mst(n);
      printf("%d\n",x);
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
