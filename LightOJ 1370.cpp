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
#define maxn 1000009
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll primes[78499];
bitset<maxn> nums;
ll m,n,row,col;
ll idx;
int phi[1000006];
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
  //trace(idx)
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
void solve(int test)
{
  scanf("%lld",&n);
  ll sum = 0;
  while(n--)
  {
    scanf("%lld",&m);
    sum += phi[m];
  }
  printf("Case %d: %lld Xukha\n",test,sum);
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
  int prev = 0;
  for(int i=0;i<78499;i++)
  {
    //from prev to primes[i]-1 make them equal to primes[i]
    for(int j=prev;j <= primes[i]-1;j++)
    {
      phi[j]=primes[i];
    }
    prev = primes[i];
  }
  //for(int i=1;i<=1000000;i++)trace(phi[i])
  test();
  return 0;
}
