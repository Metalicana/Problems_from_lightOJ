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
int h[55];
int dp[2][500002];
void solve(int test)
{
  scanf("%d",&n);
  memset(dp,-1,sizeof dp);
  int sum = 0;
  for(int i=0;i<n;i++)
  {
    scanf("%d",&h[i]);
  }
  sort(h,h+n);
  dp[0][0]=0;//dp i j means max height of towers with difference == j using first i values
  int a=0,b=1;
  for(int i=0;i<n;i++)
  {
    sum += h[i];
    memcpy(dp[1],dp[0],sizeof dp[0]);
    for(int j=0;j<=sum;j++)
    {
      if(dp[1][j]>=0)
      {
        dp[0][j+h[i]]=max(dp[0][j+h[i]],dp[1][j]+h[i]);
        dp[0][abs(j-h[i])]=max(dp[0][abs(j-h[i])],dp[1][j]+h[i]);
      }
    }
  }
  if(dp[0][0]<=0)printf("Case %d: impossible\n",test);
  else printf("Case %d: %d\n",test,dp[0][0]/2);


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
