#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000005
bool nums[maxn];
ll primes[maxn];
bool prime[maxn];
ll primo[maxn];
void siv()
{
    ll d = 0;
    primes[d++]=2;
    ll lim = sqrt(maxn * 1.0)+2;
    prime[2]=1;
    for(ll w=3;w<maxn;w+=2)
    {
        if(!nums[w])
        {
            primes[d++]=w;
            prime[w]=1;
            if(w <= lim)
            {
                for(ll q=w*w;q<maxn;q+=(2*w))nums[q]=1;
            }
        }
    }
}
bool check(ll x)
{
  ll lim = sqrt(x);
  for(int w=0;primes[w] <= lim; w++)
  {
    if(x%primes[w] == 0)return 0;
  }
  return 1;
}
int main()
{
    siv();
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll c = min(a,b);
        b = max(a,b);
        a = c;
        ll x = sqrt(b);
        ll start,ending;
        ll cnt = 0;
        int k = 0;
        if(a==b & a==1)printf("Case %d: 0\n",test);
        else if(a==b)
        {
          if(check(a))printf("Case %d: 1\n",test);
          else printf("Case %d: 0\n",test);
        }
        else
        {
          if(a == 2)cnt++;
          if(a%2==0)a++;

          for(ll i=a;i<=b;i+=2)
          {
            if(k > 1000004)cout << "DED\n";
            primo[k++] = i;
          }
          for(int i=1;primes[i]<=x;i++)
          {
            if(a%primes[i] == 0)start = a;
            else start = primes[i]*(a/primes[i] + 1);
            if(start%2==0)start+=primes[i];
            for(int j = (start-a)/2;j < b-a+1;j = j + primes[i])
            {
              if(primo[j]!=primes[i])primo[j]=-1;
            }
          }

          for(int i=0;i<=(b-a)/2;i++)
          {
            if(primo[i]>0)cnt++;
          }

          printf("Case %d: %lld\n",test,cnt);
        }
    }
    return 0;
}
