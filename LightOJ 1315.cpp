#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll ajob[4][4] = {{-2,-1,1,-3},{1,-1,-2,-3}};
ll m,n,row,col,x,y;
ll dp[505][505];
ll Grundy(ll x,ll y)
{
  if(x <0  | y < 0)return -1;
  if(x == 0 && y == 0)return 0;
  ll &ret = dp[x][y];
  if(~ret)return  ret;
  set<ll> s;
  s.insert(Grundy(x+1,y-2));
	s.insert(Grundy(x-1,y-2));
	s.insert(Grundy(x-1,y-3));
	s.insert(Grundy(x-2,y-1));
	s.insert(Grundy(x-3,y-1));
	s.insert(Grundy(x-2,y+1));
  ret = 0;
  while(s.count(ret))ret++;
  return ret;

}
void solve(ll test)
{
  scanf("%lld",&n);
  ll ans = 0;
  for(ll w=0;w<n;w++)
  {
    scanf("%lld%lld",&row,&col);
    ans = ans ^ Grundy(row,col);
  }
  if(ans == 0)printf("Case %lld: Bob\n",test);
  else printf("Case %lld: Alice\n",test);

}
set <ll> s;
void test()
{
  memset(dp,-1,sizeof dp);

  ll t;
  scanf("%lld",&t);
  for(ll test=1;test<=t;test++)
  {

    solve(test);
  }
}
int main()
{
  test();
  return 0;
}
