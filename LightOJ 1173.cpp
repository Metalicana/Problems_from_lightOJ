#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define ull unsigned long long
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
ull n,cap;
ull memo[55][55][2];
bool marker[55][55][2];
ull call(ull ss, ull bs, ull d)
{
  if(marker[ss][bs][d] != 0)return memo[ss][bs][d];
  if(ss == 0 && bs == 0)
  {
    return 1;
  }
  ull ans = 0;
  if(d == 0)
  {
    for(int i=1;i <= ss; i++)
    {
      if(ss>0)ans = ans + call(ss-i,bs+(i-1),1);
    }
  }
  else
  {
    for(int i=1;i<=bs;i++)
    {
      if(bs>0)ans = ans + call(ss+(i-1),bs-i,0);
    }
  }
  marker[ss][bs][d]=1;
  memo[ss][bs][d] = ans;
  return ans;
}
void solve(int test)
{
  scanf("%llu%lld",&n,&cap);
  if(n == 1)printf("Case %d: 1\n",test);
  else if(n == 2)printf("Case %d: 1\n",test);
  else
  {
    memset(marker,0,sizeof marker);
    memset(memo,0,sizeof memo);
    if(cap == 1)printf("Case %d: %llu\n",test,call(0,n-3,1));
    else printf("Case %d: %llu\n",test,call(cap-1,n-cap,0));
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
