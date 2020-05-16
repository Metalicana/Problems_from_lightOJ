#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
ll add(ll a, ll b ,ll c)
{
  if(a+b < c)return a+b;
  return (a+b)%c;
}
ll mul(ll a, ll b, ll c)
{
  if(a*b < c)return a*b;
  return (a*b)%c;
}
ll bigMod(ll base, ll power, ll m)
{
  if(power==0)return 1ll;
  if(power==1)return (base<m)?base:base%m;
  ll j = bigMod(base,power/2,m);
  j = mul(j,j,m);
  if(power%2==0)return j;
  return mul(j,base,m);
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,k,x,sum,y;
void solve(int test)
{
  scanf("%lld%lld%lld",&n,&k,&m);
  sum = 0;
  for(int w=0;w<n;w++)
  {
    scanf("%lld",&x);
    sum = add(sum,x,m);
  }
  y = bigMod(n,k-1,m);

  sum = mul(y,sum,m);
  sum = mul(sum, k,m);
  printf("Case %d: %lld\n",test, sum);

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
  test();
  return 0;
}
