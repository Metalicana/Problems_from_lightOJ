#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pint pair<long long, long long >
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define MOD 100000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,k,s;
int dp[3][15005];
int sum[3][15005];
int add(int x,int y)
{
  if(x+y<MOD)return x+y;
  return(x+y)%MOD;
}
void solve(int test)
{
  scanf("%d%d%d",&n,&k,&s);
  memset(dp,0,sizeof dp);
  memset(sum,0,sizeof sum);
  for(int i=1;i<=s;i++)
  {
    if(i<=k)dp[0][i]=1;
    else dp[0][i]=0;
    sum[0][i]=add(dp[0][i],sum[0][i-1]);
  }//dp[i][j] is how many ways to make j with first i die
  int l;
  for(int i=1;i<n;i++)
  {
    for(int p=1;p<=s;p++)
    {
      l = i%2;
      if(p-k-1>=0)
      {
         dp[(l^0)][p]=sum[(l^1)][p-1]-sum[(l^1)][p-k-1];
      }
      else dp[(l^0)][p]=sum[(l^1)][p-1];
      while(dp[(l^0)][p]<0)dp[(l^0)][p]+=MOD;
      sum[(l^0)][p]=add(sum[(l^0)][p-1],dp[(l^0)][p]);
    }
  }
  n%=2;
  printf("Case %d: %d\n",test,dp[n^1][s]);

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
