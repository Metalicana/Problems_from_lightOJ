#include <bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod2 1000000009
long long power1[1000005];
long long power2[1000005];
char a[1000005];
char b[1000005];
void preprocess()
{

    long long j = 117;
    long long k = 119;
    power1[0]=1ll;
    power2[0]=1ll;
    for(long long w=1; w<=1000000; w++)
    {
        power1[w] = (power1[w-1]*j)%mod1;
        power2[w] = (power2[w-1]*k)%mod2;
    }
}
int main()
{
    //freopen("o.txt","w",stdout);
    preprocess();
    int t;
    int hash_a_1,hash_a_2,hash_b_1,hash_b_2;
    int len_a,len_b;
    int k,s;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        hash_a_1 = 0;
        hash_a_2 = 0;
        hash_b_1 = 0;
        hash_b_2 = 0;
        k=0;
        s=0;
        scanf("%s%s",a,b);
        len_a = strlen(a);
        len_b = strlen(b);
        for(int w=len_b-1; w >= 0; w--)
        {
            hash_b_1 = (hash_b_1 + ((long long)b[w]-'a')*power1[k])%mod1;
            hash_b_2 = (hash_b_2 + ((long long)b[w]-'a')*power2[k])%mod2;
            k++;
        }
        k=0;
        for(int w=len_b-1; w >= 0; w--)
        {
            hash_a_1 =(hash_a_1 + ((long long)a[w]-'a')*power1[k])%mod1;
            hash_a_2 =(hash_a_2 + ((long long)a[w]-'a')*power2[k])%mod2;
            k++;
        }
        for(int w=len_b; w<len_a; w++)
        {
            if(hash_a_1 == hash_b_1 && hash_a_2 == hash_b_2)s++;
            else
            {
                if((hash_b_1-hash_a_1)%mod1 == 0 && (hash_b_2-hash_a_2)%mod2 == 0)s++;
            }
            hash_a_1 = (hash_a_1 - (power1[len_b-1]*((long long)a[w-len_b]-'a'))%mod1);
            hash_a_2 = (hash_a_2 - (power2[len_b-1]*((long long)a[w-len_b]-'a'))%mod2);
            hash_a_1 = (hash_a_1 * power1[1])%mod1;
            hash_a_2 = (hash_a_2 * power2[1])%mod2;
            hash_a_1 = (hash_a_1+(long long)a[w]-'a')%mod1;
            hash_a_2 = (hash_a_2+ (long long)a[w]-'a')%mod2;
        }
        if(hash_a_1 == hash_b_1 && hash_a_2 == hash_b_2)s++;
        else
        {
            if((hash_b_1-hash_a_1)%mod1 == 0 && (hash_b_2-hash_a_2)%mod2 == 0)s++;
        }
        printf("Case %d: %d\n",test,s);

    }
}
