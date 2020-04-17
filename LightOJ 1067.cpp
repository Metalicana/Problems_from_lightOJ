#include <bits/stdc++.h>
using namespace std;
#define mod 1000003
long long n,r;
long long ara[1000006];
long long kara[1000006];
void egcd(long long a,long long b,long long &x,long long &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return;
    }
    long long x1,y1;
    egcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return;
}
void khela()
{
    long long x,y;
    ara[0]=kara[0]=1;
    ara[1]=kara[1]=1;
    for(long long w=2;w<=1000000;w++)
    {
        ara[w] = (w*ara[w-1])%mod;
        egcd(ara[w],mod,x,y);
        kara[w] = x;
        if(kara[w]<0)
        {
            long long j = -kara[w]/mod;
            j++;
            kara[w] += (j*mod);
        }
    }

}
int main()
{
    long long t;
    khela();
    scanf("%lld",&t);
    for(long long test=1;test<=t;test++)
    {
        scanf("%lld%lld",&n,&r);
        long long ans = ((ara[n]%mod)*((kara[n-r]%mod)*(kara[r]%mod))%mod)%mod;
        printf("Case %lld: %lld\n",test,ans);

    }
    return 0;
}
