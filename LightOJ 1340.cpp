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
#define maxn 100009
#define MOD 10000019
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll primes[9594];
bitset<maxn> nums;
ll m,n,row,col;
ll idx;
void siv()
{
  int d = 0;
  primes[d++] = 2;
  for(ll i = 3; i < maxn; i += 2)
  {
    if(!nums[i])
    {
      primes[d++] = i;
      for(ll j = i*i; j < maxn; j+= (2*i))nums[j] = 1;
    }
  }
  idx = d;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  else return (a*b)%MOD;
}
ll power(ll b, ll p)
{
  if(p == 0)return 1;
  if(p == 1)return b;
  ll j = power(b,p/2);
  j = mul(j,j);
  if(p%2==0)return j;
  return mul(j,b);
}
ll bs(ll sum,ll tz)
{
 ll l = 0;
 ll r = sum;
 ll m;
 while(l < r)
 {
   m = (l+r)/2;
   if(l+1 == r)
   {
     if(sum/r >= tz)return r;
     return l;
   }
   if(sum/m < tz)r=m;
   else l=m;
 }
}
void solve(int test)
{
  ll number,tz,ans=1;
  scanf("%lld%lld",&number,&tz);
  //loop over primes
  ll sum =0;
  ll number_copy;
  ll base;
  for(int i=0;primes[i] <= number;i ++)
  {
    number_copy = number;
    base = primes[i];
    sum = 0;
    while(number_copy/base != 0)
    {
      sum += (number_copy/base);
      base = base*primes[i];
    }
    ll q = bs(sum,tz);
    //trace(sum)
    if(sum == 0 || q == 0)break;
    //trace(sum/q)
    if(sum/q >= tz)ans = mul(ans, power(primes[i],q));
  }
  if(ans == 1)printf("Case %d: -1\n",test);
  else printf("Case %d: %lld\n",test, ans);



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
  siv();
  test();
  return 0;
}
