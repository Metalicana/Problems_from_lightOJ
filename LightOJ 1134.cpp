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
ll m,n,row,col,x,y,sm;
ll cnt[100006];
ll ncr(ll x)
{
  if(x < 2)return 0;
  return (x*(x-1))/2;
}
void solve(int test)
{
  scanf("%lld%lld",&n,&m);
  memset(cnt,0,sizeof cnt);
  sm=0;
  for(int i=0;i<n;i++)
  {
    scanf("%lld",&x);
    if(i == 0){y=x;cnt[y%m]++;}
    else {y+=x;cnt[y%m]++;}
  }
  sm = ncr(cnt[0]+1);
  for(int i=1;i<m;i++)
  {
    sm += ncr(cnt[i]);
  }
  printf("Case %d: %lld\n",test,sm);

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
