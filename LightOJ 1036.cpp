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
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
ll uranium[505][505];
ll sumU[505][505];
ll radium[505][505];
ll sumR[505][505];
ll memo[505][505];
ll dp(int i, int j)
{
  if(i < 0 || j < 0)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  ll p1,p2;
  //harvest jth column from row 0 to row i for radium
  //harvest ith row from col 0 to col j for uranium
  p1 = sumU[i][j] + dp(i-1,j);
  p2 = sumR[i][j] + dp(i,j-1);
  memo[i][j] =  max(p1,p2);
  return memo[i][j];
}
void solve(int test)
{
  int i,j;
  scanf("%d%d",&m,&n);
  rep(i,m)rep(j,n)scanf("%lld",&uranium[i][j]);
  rep(i,m)rep(j,n)scanf("%lld",&radium[i][j]);
  rep(i,m)rep(j,n)
  {
    if(!j)sumU[i][j] = uranium[i][j];
    else sumU[i][j] = sumU[i][j-1]+uranium[i][j];
  }
  rep(j,n)rep(i,m)
  {
    if(!i)sumR[i][j] = radium[i][j];
    else sumR[i][j] = sumR[i-1][j]+radium[i][j];
  }
  ll ans = dp(m-1,n-1);
  printf("Case %d: %lld\n",test,ans);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(memo,-1,sizeof memo);
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
