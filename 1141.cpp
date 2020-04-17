#include <bits/stdc++.h>
using namespace std;
#define inf 100000000
#define ll long long
ll s,x;
ll primes[100005];
bool nums[1000005];
vector <ll> sex;
void siv()
{
    ll d  = 0;
    primes[d++]=2;
    for(int w=3;w<10005;w+=2)
    {
        if(nums[w]==0)
        {
            primes[d++]=w;
            if(w*w <= 100005)
            {
                for(ll q=w*w;q<10005;q+=(2*w))nums[q]=1;
            }

        }
    }
}
vector <ll> prime_fact(ll x)
{
    ll lim = sqrt(x);
    vector <ll> sex;
    for(ll w=0;primes[w]<=lim;w++)
    {
        if(x%primes[w]==0)
        {
            sex.push_back(primes[w]);
            while(x%primes[w] ==0)
            {
                x/=primes[w];
            }
        }
        lim = sqrt(x);
    }
    if(x > 1)sex.push_back(x);
    return sex;
}
ll depe[10005];
ll dp(ll a)
{
    if(a == x)return 0;
    if(a > x)return inf;
    if(depe[a]!=-1)return depe[a];
    vector <ll> bex;
    bex = prime_fact(a);
    if(bex.size() == 1 && bex[0] == a)return inf;
    ll pissant = inf;
    for(ll w=0;w<bex.size();w++)
    {
        pissant = min(pissant, 1+dp(a+bex[w]));
    }
    depe[a] = pissant;
    return depe[a];

}
int main()
{
    ll t;
    siv();
    scanf("%d",&t);
    for(ll test=1;test<=t;test++)
    {
        scanf("%d%d",&s,&x);
        memset(depe,-1,sizeof depe);
        ll ass = dp(s);
        if(ass == inf)printf("Case %lld: -1\n",test);
        else printf("Case %lld: %lld\n",test,ass);
    }
    return 0;
}
