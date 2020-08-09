#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll n,q,ara[100006],cumsum[100006];
void solve(int test)
{
  scanf("%lld%lld",&n,&q);
  for(int i=0;i<n;i++)scanf("%lld",&ara[i]);
  cumsum[n-1] = ara[n-1];
  for(int i=n-2;i>=0;i--)cumsum[i]=cumsum[i+1]+ara[i];
  ll sum = 0;
  for(int i=0;i<n-1;i++)
  {
    sum = sum + (n-i-1)*ara[i] - cumsum[i+1];
  }
  int type,x,v;
  printf("Case %d:\n",test);
  while(q--)
  {
    scanf("%d",&type);
    if(type)printf("%lld\n",sum);
    else
    {
      scanf("%d%d",&x,&v);
      sum -= (n-x-1)*ara[x];
      sum += (x)*ara[x];
      ara[x]=(ll)v;
      sum += (n-x-1)*ara[x];
      sum -= (x)*ara[x];
    }
  }

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
