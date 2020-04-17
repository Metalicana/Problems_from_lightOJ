#include <bits/stdc++.h>
using namespace std;
long long Set(long long mask,long long pos){return mask = mask|(1<<pos);}
bool Check(long long mask,long long pos){return mask&(1<<pos);}
long long dig(char x)
{
    if(x >= '0' && x <= '9')return (int)x-48;
    return (long long)x-(long long)'A'+10;
}
long long dp[(1<<16)+5][22];
char c[25];
long long b,k,woah,len;
long long call(long long mask,long long rem)
{
    if(mask == woah )
    {
        if(rem == 0)return 1;
        return 0;
    }
    if(dp[mask][rem] !=-1)return dp[mask][rem];
    long long p = 0;
    for(long long i=0;i<len;i++)
    {
        if(Check(mask,i)==0)
        {
            p += (call(Set(mask,i),(rem*b + dig(c[i]))%k));
        }
    }
    dp[mask][rem] = p;
    return dp[mask][rem];
}
int main()
{
    long long t;
    scanf("%lld",&t);
    for(long long test=1;test<=t;test++)
    {
        memset(dp,-1,sizeof dp);
        scanf("%lld%lld",&b,&k);
        scanf("%s",c);
        len = strlen(c);
        woah = (1<<len)-1;
        printf("Case %lld: %lld\n",test,call(0,0));
    }
    return 0;
}
