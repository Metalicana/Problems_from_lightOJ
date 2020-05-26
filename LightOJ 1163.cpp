#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;


void solve(int test)
{
  scanf("%lld",&n);
  m = 0;
  printf("Case %d: ",test);
  ll ans;
  ll x;
  for(ll a = 9; a >= 0; a--)
  {
    if(n%9 ==0 && a == 0)
    {
      if(m > 0)printf(" ");
      ans = n/9;
      ans *= 10;
      printf("%lld",ans);
      m++;
    }
    else if(n%9 == 0 && a == 9)
    {
      if(m > 0)printf(" ");
      ans = n/9;
      ans *= 10;
      ans--;
      printf("%lld",ans);
      m++;
    }
    else if((n%9)-a == 0 )
    {
      if(m > 0)printf(" ");
      ans = n + (n-a)/9;
      printf("%lld",ans);
      m++;
    }
  }
  printf("\n");

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
