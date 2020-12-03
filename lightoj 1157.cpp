#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
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
#define MOD 1000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
ll max(ll a, ll b);
ll L[1005][1005];
ll ocx[1005][26],ocy[1005][26];
char X[1005],Y[1005];
ll dp[1005][1005];
ll add(ll a,ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll dfs(ll ax,ll ay)
{
  //if(ax<0 || ay < 0)return 0;
  if(L[ax][ay]==0)return 1;
  if(dp[ax][ay])return dp[ax][ay];

  dp[ax][ay]=0;
  for(ll i=0;i<26;i++)
  {
    ll x = ocx[ax][i];
    ll y = ocy[ay][i];
    if(x!=-1 && y!=-1)
    {
      if(L[x][y]+1==L[ax][ay])
      {
        dp[ax][ay]=add(dp[ax][ay],dfs(x,y));
      }
    }
  }
  return dp[ax][ay];
}
ll lcs( char *X, char *Y, ll m, ll n )
{
    ll i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (X[i - 1] == Y[j - 1])
            {
              L[i][j] = L[i - 1][j - 1] + 1;
            }

        else
            {
              L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    //ocx[i][k] will return first q  such that ,0<=q<i && X[q] contains k
    for(ll i=0;i<=m;i++)
    {
      for(ll k=0;k<26;k++)
      {
        if(i==0)ocx[i][k]=-1;
        else
        {
          if(X[i-1] == k+'a')
          {
            ocx[i][k]=i-1;
          }
          else ocx[i][k]=ocx[i-1][k];
        }

      }
    }
    for(ll i=0;i<=n;i++)
    {
      for(ll k=0;k<26;k++)
      {
        if(i==0)ocy[i][k]=-1;
        else
        {
          if(Y[i-1] == k+'a')
          {
            ocy[i][k]=i-1;
          }
          else ocy[i][k]=ocy[i-1][k];
        }

      }
    }

    return dfs(m,n);
}
ll max(ll a, ll b)
{
    return (a > b)? a : b;
}
void solve(ll test)
{
    scanf("%s%s",X,Y);
    ll m = strlen(X);
    ll n = strlen(Y);
    memset(dp,0,sizeof dp);
    printf("Case %lld: %lld\n",test,lcs(X,Y,m,n));
}
void test()
{
  ll t;
  scanf("%lld",&t);
  for(ll test=1;test<=t;test++)
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
