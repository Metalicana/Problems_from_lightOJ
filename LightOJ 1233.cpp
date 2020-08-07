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
bool dp[100005];
int value[105],amount[105];
int cnt[100005];
void solve(int test)
{
  memset(dp,0,sizeof dp);
  scanf("%d%d",&n,&m);
  for(int w=0;w<n;w++)scanf("%d",&value[w]);
  for(int w=0;w<n;w++)scanf("%d",&amount[w]);

  dp[0]=1;
  for(int i=0;i<n;i++)
  {
    for(int w=0;w<=m;w++)cnt[w]=0;
    for(int j=value[i]; j <= m; j++)
    {
      if(dp[j]==0 && dp[j-value[i]]==1 &&  cnt[j - value[i]] < amount[i])
      {
        dp[j]=1;
        cnt[j] = 1 + cnt[j-value[i]];
      }
    }
  }
  int ccnt = 0;
  for(int i=1;i<=m;i++)ccnt+=dp[i];
  printf("Case %d: %d\n",test,ccnt);

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
