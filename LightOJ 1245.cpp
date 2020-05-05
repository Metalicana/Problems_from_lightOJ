#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
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

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
void solve(int test)
{
  scanf("%lld",&n);
  ll q = sqrt(n);
  ll sum = 0;
  ll endM = n+1;
  ll stM;
  ll d;
  for(ll i=1;i<=q;i++)
  {
    stM = (n)/(i+1);
    stM++;
    d = max(0ll,endM-stM);
    sum = sum + (d*i + (n/i));
    endM = stM;
    if(i == q)
    {
      if(d*i == (n/i) && d==1)sum-=(n/i);
    }
  }
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
  test();
  return 0;
}
