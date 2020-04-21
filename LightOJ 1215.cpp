#include <bits/stdc++.h>
using namespace std;
#define maxn 3000000
#define ll long long
bitset <maxn> num;
ll primes[500000];
void siv()
{
    ll d =0;
    primes[d++]=2;
    ll lim = sqrt(maxn+5);
    for(ll i=3; i<=maxn; i+=2)
    {
        if(!num[i])
        {
            primes[d++]=i;
            if(i*i <= lim)
            {
                for(ll j=i*i; j<=maxn; j+=(2*i))num[j]=1;
            }
        }
    }
}
ll power(ll b, ll p)
{

    if(p == 0)return 1;
    if(p == 1)return b;
    ll j = power(b,p/2);
    if(p%2 == 0)return j*j;
    return j*j*b;
}
int main()
{
    //freopen("o.txt","w",stdout);
    siv();
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        ll a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        ll x = (a*b)/__gcd(a,b);
        ll lim = sqrt(x);
        ll j;
        vector <pair<ll,ll> > smol;
        for(int w=0; primes[w]<=lim; w++)
        {
            if(x%primes[w]==0)
            {
                j=0;
                while(x%primes[w]==0)
                {

                    x /= primes[w];
                    j++;
                }
                smol.push_back(make_pair(primes[w],j));
            }
            lim = sqrt(x);
        }
        if(x > 1)smol.push_back(make_pair(x,1));
        lim = sqrt(l);
        vector <pair<ll,ll> > big;
        for(int w=0; primes[w]<=lim; w++)
        {
            if(l%primes[w]==0)
            {
                j=0;
                while(l%primes[w]==0)
                {
                    l /= primes[w];
                    j++;
                }
                big.push_back(make_pair(primes[w],j));
            }
            lim = sqrt(l);
        }
        if(l > 1)big.push_back(make_pair(l,1));
        bool flag = 0;
        vector <pair <ll,ll> > ans;
        if(big.size() < smol.size())flag=1;

        int w=0;
        int i = 0;
        while(i < big.size())
        {
            if(flag)break;
            if(w < smol.size())
            {
                if(big[i].first != smol[w].first)
                {
                    ans.push_back(make_pair(big[i].first,big[i].second));
                    i++;
                }
                else
                {
                    if(big[i].second < smol[w].second)flag=1;
                    else if(big[i].second > smol[w].second)ans.push_back(make_pair(big[i].first,big[i].second));
                    i++;
                    w++;
                }
            }
            else
            {
                ans.push_back(make_pair(big[i].first,big[i].second));
                i++;
            }

        }
        if(w != smol.size())flag=1;
        long long q=1ll;
        for(int w=0; w<ans.size(); w++)
        {
            q *= power(ans[w].first,ans[w].second);
        }
        if(flag)printf("Case %d: impossible\n",test);
        else printf("Case %d: %lld\n",test,q);


    }
    return 0;
}
