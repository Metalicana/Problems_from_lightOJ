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
#define rep(i,n) for(i=0;i<(n);i++)
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int primes[664580];
bitset<maxn> nums;
ll m,n,row,col;
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
}
void solve(int test)
{
  scanf("%lld",&n);
  ll x = n;
//  ll lim = sqrt((double)x);
  ll d = 1;
  ll ass = 1;
  for(int i = 0;(ll) primes[i]*primes[i] <= x; i++)
  {
    if(primes[i] == 0)break;
    if(x%primes[i] == 0)
    {
      ll j = 0;
      while(x%primes[i] == 0)
      {
        x /= primes[i];
        j++;
      }
      ass *= (2*j + 1);
      //lim = sqrt((double)x);
    }
  }
  if(x > 1)
  {
    ass *= (3);
  }
  ass = (ass+1)/2;
  printf("Case %d: %lld\n",test,ass);

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
