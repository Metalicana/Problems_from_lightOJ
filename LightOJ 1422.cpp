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
int m,n,row,col,a,b,f;
int ara[105];
int dp[105][105];
void solve(int test)
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)scanf("%d",&ara[i]);

  for(int i=0;i<=n;i++)
  {
    for(int j=1;j+i<=n;j++)
    {
      a = j;
      b = j+i;
      if(a == b)dp[a][b]=1;
      else
      {
        dp[a][b] = dp[a][b-1]+1;
        for(int k=a; k < b;k ++)
        {
          if(ara[k] == ara[b])dp[a][b] = min(dp[a][b], dp[a][k-1] + dp[k][b-1]);
        }
      }
    }
  }
  printf("Case %d: %d\n",test,dp[1][n]);
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
