#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll Set(ll N,ll pos){return N=N | (1<<pos);}
bool check(ll N,ll pos){return (bool)(N & (1<<pos));}
ll n,c,q;
ll ara[35];
vector <ll> A,B;
void punish(ll w,ll taken,ll sum,ll st, ll en,ll mask,bool j)
{
  if(w ==  taken)
  {
    if(w > taken)return;
    if(sum > c)return;
    if(!j)A.push_back(sum);
    else B.push_back(sum);
    return;
  }
  ll last = st-1;
  for(ll e=st;e<=en;e++)
  {
    if(check(mask,e))last=e;
  }
  for(ll e=last+1;e<=en;e++)
  {
    if(!check(mask,e))
    {
      punish(w,taken+1,sum+ara[e],st,en,Set(mask,e),j);
    }
  }
}
int bs(ll a)
{
  ll left = 0;
  ll right = B.size()-1;
  ll mid;
  if(left ==right)
  {
    if(B[left]+a <= c)return 0;
    return -1;
  }
  while(left < right)
  {
    mid = (left+right)/2;
    if(left + 1 == right)
    {
      if(B[right]+a <= c)return right;
      if(B[left]+a <= c)return left;
      return -1;
    }
    if(B[mid] + a <=c)
    {
      left = mid;
    }
    else right = mid;
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    scanf("%lld%lld",&n,&c);
    A.clear();
    B.clear();

    for(int w=0;w<n;w++)
    {
      scanf("%lld",&ara[w]);
    }
    q = n/2;
    for(ll w=1;w<=q+1;w++)
    {
      punish(w,0LL,0LL,0LL,q,0LL,0);
    }
    for(ll w=1;w<=n-q-1;w++)
    {
      punish(w,0LL,0LL,q+1,n-1,0LL,1);
    }
    ll ans = A.size() + B.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
  /*  for(int w=0;w<A.size();w++)cout << A[w] << " ";
    cout << endl;
    for(int w=0;w<B.size();w++)cout << B[w] << " ";
    cout << endl;*/
    int sz = A.size();
    int i;
    for(int w=0;w<sz;w++)
    {
      if(B.size()==0)break;
      i = bs(A[w]);
      if(i != -1)
      {
        ans += (i+1);
      }
    }
    printf("Case %d: %lld\n",test,ans+1);
  }
  return 0;

}
