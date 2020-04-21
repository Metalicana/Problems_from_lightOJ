#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define maxn 2000006
#define mod 1000000007
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,x,y,ans,i,a,b;
ll fact[maxn];
ll power(ll base, ll expo)
{
  if(expo == 0)return 1ll;
  if(expo == 1)return (base%mod);
  ll j = power(base,expo/2);
  j = (j*j)%mod;
  if(expo%2==0)return j;
  return (j*base)%mod;

}
void prep()
{
  fact[1]=1;
  fact[0]=1;
  for(ll i=2;i<maxn;i++)
  {
    fact[i] = (fact[i-1] * i)%mod;
  }
}
ll invFact(ll x)
{
  if(x == 1)return 1;
  return power(x,mod-2);
}
void solve(int test)
{
  scanf("%lld%lld",&n,&m);
  a = invFact(fact[m-1]);
  b = invFact(fact[n]);
  ans = (fact[n+m-1]*a)%mod;
  ans = (ans * b)%mod;
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
  prep();
  test();
  return 0;
}
