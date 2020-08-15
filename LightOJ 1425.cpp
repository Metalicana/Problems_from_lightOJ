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
long long n,r[100006];

void solve(int test)
{
  scanf("%lld",&n);
  ll b,e=0,m;
  for(int i=0;i<n;i++)
  {
    scanf("%lld",&r[i]);
    if(i == 0)b = r[i];
    else b = max(b,r[i]-r[i-1]);
  }m=b;
  for(int i=0;i<n;i++ )
  {
    if(i == 0)
    {
      if(r[i] == b)b--;
      else if(r[i] > b)
      {
        e = 1;
      }
    }
    else
    {
      if(r[i]-r[i-1] == b)b--;
      else if(r[i] - r[i-1] > b)e=1;
    }
  }
  if(e)m++;
  printf("Case %d: %lld\n",test,m);


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
