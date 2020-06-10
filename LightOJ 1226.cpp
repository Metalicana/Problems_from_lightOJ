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
ll add(ll a , ll b)
{
  if(a + b < mod)return a+b;
  return (a+b)%mod;
}
ll mul(ll a, ll b)
{
  if(a*b < mod)return a*b;
  return (a*b)%mod;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
ll fact[1000005];
ll invFact[1000005];
ll J[1005];

ll power(ll b,ll p)
{
  if(p == 0)return 1;
  if(p == 1)return b;
  ll j = power(b,p/2);
  j = mul(j,j);
  if(p%2==0)return j;
  return mul(b,j);
}
void solve(int test)
{
  int i;
  scanf("%lld",&n);
  rep(i,n)scanf("%lld",&J[i]);
  ll slot = J[0];
  ll prev = 1;
  ll ans = 1;
  for(int i=1; i<n;i ++)
  {
    ans = mul(prev, (mul(fact[slot+J[i]-1],mul(invFact[J[i]-1],invFact[slot])) ) );
    prev = ans;
    slot += J[i];
  }
  printf("Case %d: %lld\n",test,ans);

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
  fact[0]=1;invFact[0]=1;
  for(int i=1;i<1000005;i++)
  {
    fact[i] = mul(i , fact[i-1]);
    invFact[i] = power(fact[i],mod-2);
  }
  test();
  return 0;
}
