#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define x first
#define y second
#define maxn 10000000
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int primes[664580];
bitset<maxn> nums;
void siv()
{
  primes[0]=2;
  ll d = 1;
  for(ll i = 3; i < maxn; i += 2)
  {
    if(!nums[i])
    {
      primes[d++] = i;
      for(ll j = i*i; j< maxn; j+= (2*i))nums[j]=1;
    }
  }
  //trace(d)
}

ll m,n,row,col;
void solve(int test)
{
  scanf("%lld",&n);
  while(n%2==0)n/=2;
  ll x = n;
  ll ans = 1;
  for(ll i = 0; primes[i]*primes[i] <= x; i++)
  {
    if(primes[i] == 0)break;
    if(x%primes[i] == 0)
    {
      ll j = 0;
      while(x%primes[i] == 0)
      {
        x/= primes[i];
        j++;
      }
      ans *= (j+1);
    }
  }
  if(x > 1)ans *= 2;
  ans--;
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
  siv();
  test();
  return 0;
}
