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
#define LIMIT 1000000000000
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
vector <ll> s[8190];
vector<ll>fs;
vector<ll>ts;
void solve(int test)
{
  scanf("%lld%lld",&n,&m);
  printf("Case %d: %d\n",test,upper_bound(fs.begin(),fs.end(),m)-lower_bound(fs.begin(),fs.end(),n));
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
void nunu(int idx,ll num)
{
  if(idx >= (int)ts.sz)return;
  for(int i=idx; i < (int)ts.sz; i++)
  {
    ll temp = ts[i]*num;
    if(temp<=0 || temp>=LIMIT) return;
    fs.pb(temp);
    nunu(i,temp);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  ll power, answer,cnt=0,pnt=0;
  for(ll digit = 1; digit <= 12; digit++)
  {
    for(ll i = 0; i < (1 << digit); i++)
    {
      power = 1;
      answer = 0;
      for(ll q = digit-1; q >=0; q--)
      {
        if(i & (1 << q))answer = answer + power*7;
        else answer = answer + power*4;
        power = power*10;
      }
      ts.pb(answer);
    }
  }
  sort(ts.begin(),ts.end());
  nunu(0,1);
  set <ll> pasa(fs.begin(),fs.end());
  fs.assign(pasa.begin(),pasa.end());
  //trace(fs.sz)
  test();
  return 0;
}
