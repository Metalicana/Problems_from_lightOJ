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
int fat[1005],fbt[1005],tat[1005],tbt[1005];
int memo[1005][2];
int dp(int floor, int building)
{
  if(floor == n-1)
  {
    if(building == 0)return fat[floor];
    return fbt[floor];
  }
  if(memo[floor][building]!=-1)return memo[floor][building];
  int p1=INT_MAX,p2=INT_MAX;
  if(building == 0)
  {
    p1 = fat[floor] + dp(floor+1,building);
    p2 = fat[floor] + tat[floor] + dp(floor+1,1);
  }
  else
  {
    p1 = fbt[floor] + dp(floor+1,building);
    p2 = fbt[floor] + tbt[floor] + dp(floor+1,0);
  }
  memo[floor][building] = min(p1,p2);
  return memo[floor][building];
}
void solve(int test)
{
    memset(memo,-1,sizeof memo);
    scanf("%d",&n);
    for(int w=0;w<n;w++)scanf("%d",&fat[w]);
    for(int w=0;w<n;w++)scanf("%d",&fbt[w]);
    for(int w=0;w<n-1;w++)scanf("%d",&tat[w]);
    for(int w=0;w<n-1;w++)scanf("%d",&tbt[w]);
    printf("Case %d: %d\n",test,min(dp(0,0),dp(0,1)));

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
