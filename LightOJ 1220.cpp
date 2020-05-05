#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define maxn 1000000
#define pll pair<long long, long long >
#define pb push_back
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll row,col,n,m;
ll primes[maxn];
bool is_prime[maxn];
bool nums[maxn];
void siv()
{
  ll d = 0;
  primes[d++] = 2;
  is_prime[2] = 1;
  for(ll i =3; i < maxn; i += 2)
  {
    if(!nums[i])
    {
      primes[d++] = i;
      is_prime[i] = 1;
      for(ll j = i*i; j < maxn; j+= (2*i))nums[j]=1;
    }
  }
}
ll expo(ll b, ll p)
{
  if( p == 0)return 1;
  if(p == 1)return b;
  ll j = expo(b,p/2);
  if(p%2==0)return  j*j;
  return (j*j*b);
}
ll sod(ll x)
{
  ll sq = sqrt(x);
  ll ans = 1;
  ll p=0;
  vector < pll > ass;
  for(ll i = 0; primes[i] <= sq; i++)
  {
    if(x % primes[i] == 0)
    {
      p=0;
      ans++;
      while(x%primes[i]==0)
      {
        x/=primes[i];
        p++;
      }
      ass.pb(pll(primes[i],p));
      sq = sqrt(x);
    }
  }
  if(x > 1)
  {
    ass.pb(pll(x,1));
  }
  int stick = 0;
  for(int w=0;w<(int)ass.size();w++)
  {
    ans = w==0?ass[w].second:__gcd(ass[w].second,ans);
  }
  return ans;
}
void solve(int test)
{
  m = sod(abs(n));
  if(n > 0 ||m%2 ==1)
  {
    printf("Case %d: %lld\n",test,m);
  }
  else
  {
    while(m%2==0)m/=2;
    printf("Case %d: %lld\n",test,m);
  }

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    scanf("%lld",&n);
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
