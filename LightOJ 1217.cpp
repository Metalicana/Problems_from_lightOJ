#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll n,c[1005];
ll memo[1005][1005];
ll goback(ll i)
{
  if(i == 0)return n-1;
  return i-1;
}
ll dp(ll i, ll j)
{
  if(i == j)return c[i];
  if(i > j)return 0;
  if(memo[i][j]!=-1)return memo[i][j];
  ll p1=0,p2=0;
  if(goback(i) == j)p1 = c[i] + dp(i+2,j-1);
  else p1 = c[i] + dp(i+2,j);
  p2 = dp(i+1,j);
  memo[i][j] = max(p1,p2);
  return memo[i][j];
}
void solve(int test)
{
  scanf("%lld",&n);
  for(ll w=0;w<n;w++)scanf("%lld",&c[w]);
  ll ans = dp(0,n-1);
  printf("Case %d: %lld\n",test,ans);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(memo,-1,sizeof memo);
    solve(test);
  }
}
int main()
{
  test();
  return 0;
}
