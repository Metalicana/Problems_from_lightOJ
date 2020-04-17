#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
ll n,k,val[55],lim[55];
ll memo[55][1005];
ll dp(ll i,ll make)
{
    if(i >= n)
    {
        if(make == 0)return 1;
        return 0;
    }
    if(memo[i][make]!=-1)return memo[i][make];
    ll p1 = 0;
    for(ll w=1;w<=lim[i];w++)
    {
        if(make - (w*val[i]) >= 0)
        {
            p1 += dp(i+1,make-(w*val[i]));
        }
    }
    p1 += dp(i+1,make);
    memo[i][make] = p1%mod;
    return memo[i][make];
}
int main()
{
    ll t;

    scanf("%lld",&t);
    for(ll test=1;test<=t;test++)
    {
        memset(memo,-1,sizeof memo);
        scanf("%lld%lld",&n,&k);
        for(ll w=0;w<n;w++)scanf("%lld",&val[w]);
        for(ll w=0;w<n;w++)scanf("%lld",&lim[w]);
        printf("Case %lld: %lld\n",test,dp(0,k));
    }
    return 0;
}
