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
#define maxn 100000
#define mod 100000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll a,b;
set<ll>listItems;
vector<ll>final;
ll fact[1000001];
ll invFact[1000001];
ll power(ll b,ll p)
{
  if(p ==0 )return 1;
  if(p == 1)return b;
  ll j = power(b,p/2);
  j = j*j;
  if(p%2==0)return j;
  return j*b;
}
ll power2(ll b,ll p)
{
  if(p ==0 )return 1;
  if(p == 1)return b%mod;
  ll j = power2(b,p/2);
  j = (j*j)%mod;
  if(p%2==0)return j;
  return (j*b)%mod;
}
ll catalan(ll x)
{
  //trace2(fact[2*x],invFact[x])
  ll y = fact[2*x]%mod;
  y = (y*invFact[x])%mod;
  y = (y*invFact[x])%mod;
  y = (y*power2(x+1,mod-2))%mod;
  return y;
}
void solve(int test)
{
  scanf("%lld%lld",&a,&b);
  long long res=upper_bound(final.begin(),final.end(),b)-lower_bound(final.begin(),final.end(),a);
  if(res<=0) printf("Case %d: 0\n",test);
  else printf("Case %d: %lld\n",test,catalan(res));

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
  ll j,k;
  //freopen("o.txt","w",stdout);
  for(ll i = 2; i <= 100000; i++)
  {
    j = 2;
    while(true)
    {
      k = power(i,j);
      if(k > 10000000000)break;
      listItems.insert(k);
      j++;
    }
  }
  fact[0] = 1;
  invFact[0] = 1;
  for(ll i = 1; i < 1000001; i++)
  {
    fact[i] = (fact[i-1]*i)%mod;
    invFact[i] = power2(fact[i],mod-2);
  }
  for(auto x: listItems)final.pb(x);
  test();
  return 0;
}
