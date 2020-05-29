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
#define maxn 100000
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,x,k,tc;
int happ[35];
int keep[35][35];
int discard[35][35];
map<int,bool> check;
void solve(int test)
{
  memset(keep,0,sizeof keep);
  memset(discard,0,sizeof discard);
  memset(happ,0,sizeof happ);
  check.clear();
  scanf("%d%d%d",&n,&m,&k);
  for(int i = 0;i < n; i ++)
  {
    for(int q=0;q<k;q++)
    {
      scanf("%d",&x);
      if(x < 0)
      {
        discard[i][x*-1] = 1;
      }
      else
      {
        keep[i][x] = 1;
      }
    }
  }
  scanf("%d",&tc);

  while(tc--)
  {
    scanf("%d",&x);
    check[x]=1;

  }
  for(int i=1;i<=m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(!check[i])
      {
        if(discard[j][i]==1)happ[j]=1;
      }
      else
      {
        if(keep[j][i] == 1)happ[j]=1;
      }
    }
  }
  bool flag = 0;
  for(int i = 0; i < n; i++)
  {
    if(happ[i]==0)
    {
      flag = 1;
      break;
    }
  }
  if(!flag)printf("Case %d: Yes\n",test);
  else printf("Case %d: No\n",test);
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
