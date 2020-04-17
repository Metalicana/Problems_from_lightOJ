#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,q,m,d;
ll ara[205];
ll memo[205][21][12];
ll mod(ll a, ll p)
{
  ll x = a/p;
  if(a < 0 && a%p != 0)x--;
  return a - x*p;
}
ll dp(ll i,ll k,ll taken)
{
  if(memo[i][k][taken]!=-1)return memo[i][k][taken];
  if(i > n)return 0;
  if(taken == m)
  {
    if(k == 0)return 1;
    return 0;
  }
  ll ret1=0,ret2=0;
  ret1 = dp(i+1,mod(k+ara[i],d),taken+1);
  ret2 = dp(i+1,k,taken);
  memo[i][k][taken] = ret1+ret2;
  return memo[i][k][taken];
}
int main()
{
//  freopen("o.txt","w",stdout);
  ll t;
  scanf("%lld",&t);
  for(ll test=1;test<=t;test++)
  {
    scanf("%lld%lld",&n,&q);
    for(ll w=0;w<n;w++)
    {
      scanf("%lld",&ara[w]);
    }
    printf("Case %lld:\n",test);
    for(ll w=0;w<q;w++)
    {
      scanf("%lld%lld",&d,&m);
      memset(memo,-1,sizeof memo);
      printf("%lld\n",dp(0,0,0));
    }
  }
  return 0;
}
