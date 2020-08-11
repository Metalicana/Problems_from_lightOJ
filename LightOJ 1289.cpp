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
#define maxn 100000006
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int primes[5761456];
unsigned int ans[5761456];

bitset<maxn> nums;
int n, idx;
unsigned int pf(int x)
{
  int sex;
  unsigned int cnt=1;
  for(int i=0;primes[i]*primes[i] <= x; i++)
  {
    sex = x/primes[i];
    while(sex >= primes[i])
    {
      cnt *= primes[i];
      sex /= primes[i];
    }
  }
  return cnt;
}
void siv()
{
  int d = 0;
  primes[d++] = 2;
  ans[d-1] = 2;
  for(ll i = 3; i < maxn; i += 2)
  {
    if(!nums[i])
    {
      primes[d++] = i;
      ans[d-1] = ans[d-2]*i;
      for(ll j = i*i; j < maxn; j+= (2*i))nums[j] = 1;
    }
  }
  idx = d;
}
void solve(int test)
{
  scanf("%d",&n);
  printf("Case %d: %u\n",test,pf(n)*(ans[upper_bound(primes,primes+5761455,n)-primes-1]));

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
