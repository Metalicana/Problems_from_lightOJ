#include <bits/stdc++.h>
using namespace std;
#define mod 10056
#define ll long long

ll ncr1[10001];
ll ncr2[10001];
ll f[10001];
int main()
{

  f[0] = 1;
  f[1] = 1;
  f[2] = 3;
  ncr1[1] = 1;
  ncr2[1] = 2;
  ncr2[2] = 1;
  ll x = 0;
  for(ll w=3;w<=1000;w++)
  {
    for(ll q=w-1,r=1;q>=0;q--,r++)
    {

      if(w%2==1)
      {
        if(r == 1)ncr1[r] = w;
        else if(r == w)ncr1[r] = 1;
        else ncr1[r] = (ncr2[r-1] + ncr2[r])%mod;
        x = ncr1[r];
      }
      else
      {
        if(r == 1)ncr2[r] = w;
        else if(r == w)ncr2[r] = 1;
        else ncr2[r] = (ncr1[r-1] + ncr1[r])%mod;
        x = ncr2[r];
      }
      f[w] = (f[w] + x * f[q])%mod;
    }
  }
  ll t;
  scanf("%lld",&t);
  ll n;
  for(ll test=1;test<=t;test++)
  {
    scanf("%lld",&n);
    printf("Case %lld: %lld\n",test,f[n]);
  }
  return 0;
}
