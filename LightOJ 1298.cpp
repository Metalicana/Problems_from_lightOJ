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
#define maxn 10000
#define MOD 1000000007
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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
vector<ll> primes;
bitset<maxn>num;
//TEMPLATE ENDS HERE, SO DOES MY WILL TO LIVE
void siv()
{
  primes.pb(2);
  for(ll i=3;i<maxn;i+=2)
  {
    if(!num[i])
    {
      primes.pb(i);
      for(ll j=i*i;j<maxn;j+=(2*i))num[j]=1;
    }
  }
}
ll power(ll b, ll p)
{
  if(p==0)return 1;
  if(p == 1)return b;
  ll x = power(b,p/2);
  x=mul(x,x);
  if(p%2==0)return x;
  return mul(x,b);
}
ll k,p;
ll memo[505][505];
ll b[505];
void solve(int test)
{
  scanf("%lld%lld",&k,&p);
  ll ans = mul(b[p-1],memo[p][k-p]);
  printf("Case %d: %lld\n",test,ans);
}
void test()
{
  siv();
  ll x=1;
  b[0]=1;
  for(int i=1;i<500;i++)
  {
    b[i] = mul(b[i-1],primes[i]-1);
  }
  for(int i=0;i<=500;i++)
  {
    memo[1][i]=x;
    x=mul(x,2ll);
  }
  for(p=2;p<=500;p++)
  {
    for(ll sum=0;sum<=500;sum++)
    {
      x=1;
      for(ll j=0;j<=sum;j++)
      {
        memo[p][sum] =add(mul(memo[p-1][sum-j],x),memo[p][sum]);
        x=mul(x,primes[p-1]);
      }
    }
  }
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
