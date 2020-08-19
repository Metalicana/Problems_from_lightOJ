#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll unsigned long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define MOD 1000000007
#define M 4294967296
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll s;
struct matrix
{
  ll row, col, v[55][55];
};
ll add(ll a, ll b)
{
  if(a>=M)a=a%M;
  if(b>=M)b=b%M;
  if(a+b < M)return a+b;
  return (a+b)%M;
}
ll mul(ll a, ll b)
{
  if(a >= M)a=a%M;
  if(b >= M)b=b%M;
  if(a*b < M)return a*b;

  return (a*b)%M;
}
matrix identity_matrix;
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (ll i = 0; i < r.row; i++) {
    for (ll j = 0; j < r.col; j++) {
      ll sum = 0;
      for (ll k = 0; k < a.col;  k++) {
        sum =add(sum, mul(a.v[i][k],b.v[k][j]));
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}
matrix power(matrix mat, ll p)
{
  vector<int> sex;
  while(p!=0)
  {
    sex.pb(p%2);
    p/=2;
  }
  reverse(sex.begin(),sex.end());
  matrix pat = identity_matrix;
  for(auto video : sex)
  {
    if(video)pat = multiply(multiply(pat,pat),mat);
    else pat = multiply(pat,pat);
  }
  return pat;
}
ll ncr[55][55];
ll factorize(ll a, ll b,ll c)
{
  if(b<c)swap(b,c);
  s= max(s,c);
  ll x = 1;
  ll y = 1;
  ll i = b+1;
  ll j = 1;
  while(i <= a && j <= c)
  {
    if(i<=a)x = x*i;
    if(j<=c)y = y*j;
    s = __gcd(x,y);
    x/=s;
    y/=s;
    i++;
    j++;
  }
  return x;
}
void solve(int test)
{
  ll n,k;
  scanf("%llu%llu",&n,&k);
  matrix mat;
  identity_matrix.row = identity_matrix.col = k+2;
  mat.row = mat.col = k+2;

  for(int i=0;i<=k+1;i++)for(int j=0;j<=k+1;j++)mat.v[i][j]=0;
  for(int i=0;i<=k+1;i++)mat.v[0][i]=1;
  for(int i=k+1;i>0;i--)
  {
    for(int j=k+1;j>=i;j--)
    {
      if(i == j || j==k+1 )mat.v[j][i]=1;
      else mat.v[j][i] = mat.v[j][i+1] + mat.v[j+1][i+1];
    }
  }
  matrix pat;

  pat.row = k+2, pat.col = 1;
  for(int i=0;i<k+2;i++)
  {
    if(i <= 1)pat.v[i][0] = 1;
    else pat.v[i][0]=ncr[k][i-1]%M;
  }
  if(n == 1)printf("Case %d: 1\n",test);
  else
  {
    mat = power(mat,n-1);
    pat = multiply(mat,pat);

    printf("Case %d: %llu\n",test,pat.v[0][0]%M);
  }


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

  for(int i=0;i<55;i++)
  {
    for(int j=0;j<55;j++)
    {
      if(i == j)identity_matrix.v[i][j]=1;
      else identity_matrix.v[i][j]=0;
    }
  }
  ncr[0][0]=1;

    for(int i=1;i<=50;i++)
    {
        ncr[i][0]=1;
        for(int j=1;j<=i;j++)
            ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
    }

  test();
  return 0;
}
