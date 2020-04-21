#include <bits/stdc++.h>
using namespace std;
#define maxn 10000000
#define ll long long
bool num[maxn];
bool is_primes[maxn];
vector <int> primes;
int d;
void siv()
{
    d=0;
    is_primes[2]=1;
    primes.push_back(2);
    ll lim = sqrt(maxn);
    for(ll i=3;i<=maxn;i+=2)
    {
        if(!num[i])
        {
            is_primes[i]=1;
            primes.push_back(i);
            if(i < lim)
            {
                for(ll j=i*i;j<=maxn;j+=(2*i))num[j]=1;
            }
        }
    }
}
int main()
{
    siv();
    int t,n;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        int k=0;
        for(int i=0;primes[i]<=n;i++)
        {

            if(is_primes[n-primes[i]])k++;
        }
        printf("Case %d: %d\n",test,k);
    }
}
