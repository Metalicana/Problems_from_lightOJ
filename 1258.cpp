#include <bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod2 1000000009
long long power1[1000005],power2[1000005];
char c[1000005];
long long power(long long b,long long p,long long mod)
{

    if(p==0)return 1;
    if(p==1)return b%mod;
    long long j = power(b,p/2,mod);
    if(p%2==0)return (j*j)%mod;
    return ((j*j)%mod * b%mod)%mod;
}
long long invMod(long long a, long long p)
{
    return power(a,p-2,p);
}
void preprocess()
{
    long long j = 103;
    long long k = 119;
    power1[0] = power2[0]=1;
    for(int w=1; w<=1000000; w++)
    {
        power1[w] = (power1[w-1]*j)%mod1;
        power2[w] = (power2[w-1]*k)%mod2;
    }

}
int main()
{
    preprocess();
    int t;
    scanf("%d",&t);
    long long hash_left_1,hash_right_1,len,k,hash_left_2,hash_right_2;
    for(int test=1; test<=t; test++)
    {
        scanf("%s",c);
        hash_left_1 = 0;
        hash_left_2 = 0;
        hash_right_1 = 0;
        hash_right_2 = 0;
        len = strlen(c);
        k=1;
        for(int w=len - 1; w>=0; w--)
        {
            hash_left_1 = (hash_left_1 + ((long long)c[w]-'a')*power1[k])%mod1;
            hash_left_2 = (hash_left_2 + ((long long)c[w]-'a')*power2[k])%mod2;
            hash_right_1 = (hash_right_1 + ((long long)c[w]-'a')*power1[len-k+1])%mod1;
            hash_right_2 = (hash_right_2 + ((long long)c[w]-'a')*power2[len-k+1])%mod2;
            k++;
        }
        //cout << hash_left_1 << " " << hash_right_1 << " " << hash_left_2 << " " << hash_right_2 << endl;
        long long x = invMod(power1[1],mod1);
        long long y = invMod(power2[1],mod2);
        long long ans;
        for(int w=0; w<len; w++)
        {

            if((hash_left_1 - hash_right_1)%mod1 == 0 && (hash_left_2-hash_right_2)%mod2==0)
            {
                ans = len+w;
                break;
            }
            hash_left_1 = ((hash_left_1 - (((long long)c[w]-'a')*power1[len-w])%mod1)%mod1 + mod1)%mod1;
            hash_left_2 = ((hash_left_2 - (((long long)c[w]-'a')*power2[len-w])%mod2)%mod2 + mod2)%mod2;
            hash_right_1 = ((hash_right_1 - (((long long)c[w]-'a')*power1[1])%mod1)%mod1 + mod1)%mod1;
            hash_right_1 = (x*hash_right_1)%mod1;
            hash_right_2 = ((hash_right_2 - (((long long)c[w]-'a')*power2[1])%mod2)%mod2 + mod2)%mod2;
            hash_right_2 = (y*hash_right_2)%mod2;
           // printf("%lld %lld %lld %lld\n",hash_left_1,hash_right_1,hash_left_2,hash_right_2);

        }
        if((hash_left_1 - hash_right_1)%mod1 == 0 && (hash_left_2-hash_right_2)%mod2==0)
        {
            ans = min(ans,2*len - 1);
        }
        printf("Case %d: %lld\n",test,ans);

    }
    return 0;
}
