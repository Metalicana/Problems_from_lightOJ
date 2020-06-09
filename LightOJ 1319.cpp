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
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
long long n,m;
long long P[15],R[15],Mx[15],Yx[15];
long long power(ll b, ll p, ll mod)
{
  if( p ==0)return 1;
  if( p == 1)return b%mod;
  ll j = power(b,p/2,mod);
  j = (j*j)%mod;
  if(p%2==0)return j;
  return (j*b)%mod;
}
void solve(int test)
{
  scanf("%lld",&n);
  int i;
  rep(i,n)scanf("%lld%lld",&P[i],&R[i]);
  long long M = 1;
  rep(i,n)M=M*P[i];
  rep(i,n)Mx[i]=M/P[i];
  rep(i,n)Yx[i]=power(Mx[i],P[i]-2,P[i]);
  ll sum = 0;
  rep(i,n)sum += Yx[i]*R[i]*Mx[i];
  sum %= M;
  printf("Case %d: %lld\n",test,sum);

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
