#include <bits/stdc++.h>
using namespace std;
#define maxn 69000
#define mod 1000000007
long long bm(long long a,long long b)
{
    if(b==0)return 1;
    if(b==1)return a;
    long long j = bm(a,b/2);
    if(b%2==0)return (j*j)%mod;
    return ((j*j)%mod * a)%mod;
}
bool num[maxn];
long long primes[maxn];
void siv()
{
    primes[0] = 2;
    long long x=1;
    long long lim = sqrt(maxn);
    for(long long w=3; w<=maxn; w+=2)
    {
        if(!num[w])
        {
            primes[x++]=w;
            if(w<=lim)
            {
                for(long long i=w*w; i<=maxn; i+=2*w)
                {
                    num[i]= 1;
                }
            }
        }
    }
}
long long sod(long long x,long long s)
{
    long long sq = sqrt(x*1.0);
    long long c = 0;
    long long sum=0,j;
    long long bum = 1;
    long long kass ,lass,ex,wai;
    while(primes[c]<=sq)
    {
        j=0;
        sum = 0;
        while(x%primes[c]==0)
        {
            x = x/primes[c];
            j++;

        }
        kass = j*s +1;
        lass = (bm(primes[c],kass)-1);
        ex = bm(primes[c]-1,mod-2);
        sum += (lass*ex%mod);
        sum = sum%mod;
        bum = (bum*sum)%mod;
        sq = sqrt(x*1.0);
        c++;
    }
    if(x!=1)
    {
        sum = 0;
        kass = s +1;
        lass = (bm(x,kass)-1);
        ex = bm(x-1,mod-2);
        sum += ((lass*ex)%mod);
        sum = sum%mod;
        bum = (bum*sum)%mod;
    }
    return bum;
}
int main()
{
    //freopen("o.txt","w",stdout);
    siv();
    long long x,y;
    long long t,a,b;
    long long ans;
    scanf("%lld",&t);
    for(long long i=1; i<=t; i++)
    {
        scanf("%lld%lld",&a,&b);
        if(a % mod == 0)
        {
            a /= mod;
        }
        ans = sod(a,b);
        printf("Case %lld: %lld\n",i,ans);
    }

    return 0;
}

