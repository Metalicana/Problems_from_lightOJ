#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
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
ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,k;
ll memo[55][55];
ll dp(ll portions_left,ll i)
{
  if(i >= k)return 1;
  ll ans = 0;
  if(memo[portions_left][i]!=-1)return memo[portions_left][i];
  for(ll take = 1; take <= m; take++)
  {
    if((k-i-1)*m + take < portions_left)continue;
    else if(k-i-1+take>portions_left)break;
    else ans += dp(portions_left-take,i+1);
    //if take, underflows continue
    //if take, overflows, break
  }
  memo[portions_left][i]=ans;
  return ans;

}
void solve(ll test)
{
  scanf("%lld%lld%lld",&n,&k,&m);
  memset(memo,-1,sizeof memo);
  printf("Case %lld: %lld\n",test, dp(n,0));
}
void test()
{
  ll t;
  scanf("%lld",&t);
  for(ll test=1;test<=t;test++)
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
