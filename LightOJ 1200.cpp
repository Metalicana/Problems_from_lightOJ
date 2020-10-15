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
int m,n,row,col,W;
int p[105],c[105],w[105];
int memo[105][10006];
int dp(int i,int weight)
{
  if(i >= n)return 0;
  if(memo[i][weight]!=-1)return memo[i][weight];
  int p1=0,p2=0;
  if(weight - w[i] >= 0)p1 = p[i] + dp(i,weight-w[i]);
  p2 = dp(i+1,weight);
  memo[i][weight] = max(p1,p2);
  return memo[i][weight];
}
void solve(int test)
{
  memset(memo,-1,sizeof memo);
  scanf("%d%d",&n,&W);
  for(int i=0;i<n;i++)
  {
    scanf("%d%d%d",&p[i],&c[i],&w[i]);
    W -= c[i]*w[i];
  }
  if(W<0)printf("Case %d: Impossible\n",test);
  else
  {
    printf("Case %d: %d\n",test,dp(0,W));
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
