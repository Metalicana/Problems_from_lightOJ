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
int m,n,row,col,sum,d;
int ara[105];
ll dp[100005];
//dp[i][j] = dp[i-1][j] | (dp[i-1][j] << ara[i])
void solve(int test)
{
  scanf("%d",&n);
  sum = 0;
  memset(dp,0,sizeof dp);
  for(int i=0;i<n;i++)scanf("%d",&ara[i]),sum+=ara[i];
  if(n%2==1)ara[n]=0,n++;
  dp[0]=1;
  for(int i=0;i<n;i++)
  {
    for(int j=sum-ara[i]; j>=0; j--)
    {
      dp[j+ara[i]]|=(dp[j]<<1LL);
    }
  }
  int minX = INT_MAX;
  for(int i=sum;i>=0;i--)
  {
    if( (dp[i]&(1LL<<(n/2) ) ) || (dp[i]&(1LL<<((n+1) /2) ) )   )
            {
                if(minX>abs(sum-2*i) )
                {
                    minX=abs(sum-2*i);
                }
            }
  }
  int y = (sum-minX)/2;
  int x = sum-y;
  printf("Case %d: %d %d\n",test,y,x);
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
