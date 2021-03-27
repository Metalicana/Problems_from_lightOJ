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
#define eps 1e-9
#define maxn 100000
#define MOD 100000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}
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
ll sub(ll a, ll b)
{
  if(a >= b)return (a-b)%MOD;
  return ((a-b)%MOD+MOD)%MOD;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE
ll np[2][15001],ntp[2][15001],dp[2][15001];
ll n,k,s;

void solve(int test)
{
  scanf("%lld%lld%lld",&n,&k,&s);
  memset(dp,0,sizeof dp);
  memset(np,0,sizeof np);
  memset(ntp,0,sizeof ntp);
  for(ll i=1;i<=k;i++)
  {
    dp[1][i]=i;
    np[1][i]=add(np[1][i-1],dp[1][i]);
    ntp[1][i]=add(ntp[1][i-1],mul(i,dp[1][i]));
  }
  for(ll i=k+1;i<=s;i++)
  {
    np[1][i] = np[1][k];
    ntp[1][i] = ntp[1][k];
  }
  ll lim;
  ll p,q;

  for(ll i=2;i<=n;i++)
  {
    lim = min(k*i,s);
    p=i%2;
    for(ll sum=1;sum<=s;sum++)
    {
      q = sum-min(sum,k)-1;
      if(q<0)q++;
      if(sum<i)
      {
        np[p][sum]=0;
        ntp[p][sum]=0;
        dp[p][sum]=0;
      }
      else if(sum>lim)
      {
        np[p][sum]=np[p][lim];
        ntp[p][sum]=ntp[p][lim];
      }
      else
      {
        dp[p][sum] = sub(mul(sub(np[p^1][sum-1],np[p^1][q]),sum),sub(ntp[p^1][sum-1],ntp[p^1][q]));
        np[p][sum] = add(np[p][sum-1],dp[p][sum]);
        ntp[p][sum] = add(ntp[p][sum-1],mul(sum,dp[p][sum]));
      }
    }

  }
  p = n%2;
  printf("Case %d: %lld\n",test, dp[p][s]);
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
