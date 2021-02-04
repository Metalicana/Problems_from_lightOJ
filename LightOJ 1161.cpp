#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 10004
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
bool check(ll mask,ll i){return ((1<<i)&mask);}
ll Set(ll mask,ll i){return mask | (1<<i);}
ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
ll dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
ll dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col;
bitset<maxn> num;
vector<ll>primes;
ll sex[maxn];
ll ncr[maxn][5];
bool marked[maxn];
void siv()
{
  primes.pb(2);
  for(ll i=3;i<maxn;i+=2)
  {
    if(!num[i])
    {
      primes.pb(i);
      if(i*i < maxn)
      {
        for( ll j=i*i;j<maxn;j+=(2*i))num[j]=1;
      }
    }
  }
  ncr[4][0]=1;
  ncr[4][1]=4;
  ncr[4][2]=6;
  ncr[4][3]=4;
  ncr[4][4]=1;
  for(ll i=5;i<maxn;i++)
  {
    for(ll j=0;j<=4;j++)
    {
      if(j == 0)ncr[i][j]=1;
      else if(j==1)ncr[i][j]=i;
      else
      {
        ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
      }
    }
  }
}
void solve(ll test)
{
  scanf("%lld",&n);
  memset(sex,0,sizeof sex);
  memset(marked,0,sizeof marked);
  vector<ll>video;
  vector<pii>peepee;
  ll lim=(ll)primes.sz;
  ll putki;
  ll ans = ncr[n][4];
  for(ll p=0;p<n;p++)
  {
    video.clear();
    scanf("%lld",&m);
    for(ll q=0;q < lim && primes[q]*primes[q] <= m; q++)
    {
      if(m%primes[q]==0)
      {
        video.pb(primes[q]);
        while(m%primes[q]==0)m/=primes[q];
      }
    }
    if(m > 1)video.pb(m);
    putki = (ll)video.sz;
    ll temp;
    ll pp=0;
    for(ll i=1;i<(1<<putki);i++)
    {
      temp = 1;
      pp=0;
      for(ll q=0;q<putki;q++)
      {
        if(check(i,q))
        {
          temp*=video[q];
          pp++;
        }
      }
      sex[temp]++;
      if(sex[temp]>=4 && !marked[temp])
      {
        marked[temp]=1;
        peepee.pb(mp(temp,pp));
      }
    }
  }
  for(auto poopoo : peepee)
  {
    if(poopoo.y%2==1)
    {
      ans-=ncr[sex[poopoo.x]][4];
    }
    else ans += ncr[sex[poopoo.x]][4];
  }
  printf("Case %lld: %lld\n",test,ans);

}
void test()
{
  siv();
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
  test();
  return 0;
}
