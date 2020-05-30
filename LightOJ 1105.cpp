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
ll m,n,row,col;
ll f[55];
ll sum[55];
int pasa[64];
void solve(ll test)
{
  scanf("%lld",&n);
  ll i,tr=0;
  ll sumone = 0;
  int mx;
  memset(pasa,0,sizeof pasa);
  while(n>0)
  {
    tr++;
    i=1;
    while(sum[i] < n)i++;
    i--;
    if(tr == 1)mx=i;
    n -= (sum[i]+1);
    pasa[i]=1;

  }

  printf("Case %lld: ",test);
  for(i=mx;i>=0;i--)printf("%lld",pasa[i]);
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

  //freopen("o.txt","w",stdout);
  f[1] = 1;
  f[2] = 1;
  sum[1] = 1;
  sum[2] = 2;
  for(ll i=3;i<50;i++)
  {
    f[i] = f[i-1] + f[i-2];
    sum[i] = sum[i-1] +f[i];
  }
  test();
  return 0;
}

/*tr++;
i = 1;
while(sum[i]<=n)i++;
i--;
if(sum[i] == n && tr == 1)i--;
if(sum[i]==n){sumone += (1 << (i-1));n = n - sum[i];}
else{  sumone += (1 << (i));n = n - sum[i] - 1;}*/
