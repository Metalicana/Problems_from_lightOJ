#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll power(ll b,ll p, ll m)
{
  if(p == 0)return 1;
  if(p == 1)return b%m;
  ll j = power(b,p/2,m);
  j = (j*j)%m;
  if(p%2==0)return j;
  return (j*b)%m;
}
double pew(double n, ll k, double x, ll y)
{
  if(k == 0 && y==0)return 1;
  if(k == 0 && y != 0)return 1.0/(double)power((ll)x,y,100000000000000000);
  if(k!=0 && y==0)return (double)power((ll)(n),k,100000000000000000);
  double j = pew(n,k/2,x,y/2);
  j = j*j;
  if(k%2==1)j*=(n);
  if(y%2==1)j/=(x);
  return j;
}
ll m,n,row,col,k;
void solve(ll test)
{
  scanf("%lld%lld",&n,&k);
  ll a;
  double x;
  ll ass = 0;
  if(k*log10(n)+1 <= 3)
  {
    a = power(n,k,1000);
    m = a;
    ass = 1;
  }
  else
  {
    a = power(n,k,1000);
    x = pew(n,k,10,k*log10(n)-2);
    m = (ll)x;
  }
  vector<ll> aa;
  for(ll w=0;w<3;w++)aa.pb(a%10),a/=10;
  vector<ll> mm;
  for(ll w=0;w<3;w++)mm.pb(m%10),m/=10;
  printf("Case %lld: ",test);
  if(ass)reverse(mm.begin(),mm.end());
  for(ll w=2;w>=0;w--)
  {
    printf("%lld",mm[w]);
  }
  printf(" ");
  for(ll w=2;w>=0;w--)
  {
    printf("%lld",aa[w]);
  }
  printf("\n");



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
//  freopen("o.txt","w",stdout);
  test();
  return 0;
}
