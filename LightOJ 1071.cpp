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
#define maxn 105
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define rep(i,n) for(i=0;i<(n);i++)
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
int dp[maxn][maxn][maxn][4];
int grid[maxn][maxn];
int go(int row, int c1,int c2, int nextMove)
{
  if(row == n-1 && c1 == m-1 && c2 == m-1 && nextMove == 0)return 0;
  if(dp[row][c1][c2][nextMove]!=-1)return dp[row][c1][c2][nextMove];
  int res = 0;
  if(nextMove == 0)
  {
    if(c1 +1 < c2 )res = max(go(row,c1+1,c2,0)+grid[row][c1+1],res);
    res = max(go(row,c1,c2,1),res);
  }
  else if(nextMove == 1)
  {
    if(c2 + 1 < m)res=max(res, go(row, c1, c2+1, 1) + grid[row][c2+1]);
    if(c2 > c1) res = max(res, go(row, c1, c2, 2));
  }
  else
  {
    if(c1 < c2  && row+1 < n)res = max(res,go(row+1,c1,c2,0)+grid[row+1][c1]+grid[row+1][c2]);
  }
  dp[row][c1][c2][nextMove] = res;
  return dp[row][c1][c2][nextMove];
}
void solve(int test)
{
  int i,j,k;
  scanf("%d%d",&n,&m);
  rep(i,n)rep(j,m)scanf("%d",&grid[i][j]);
  printf("Case %d: ",test);
  int res = go(0,0,0,1) + grid[0][0];
  printf("%d\n",res);

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(dp,-1,sizeof dp);
    solve(test);
  }
}
int main()
{
  test();
  return 0;
}
