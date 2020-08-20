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
#define M 10007
#define MOD 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
struct matrix
{
  ll row, col, v[3][3];
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
void solve(int test)
{
  scanf("%d",&n);
  matrix mat;
  mat.row = mat.col = 3;
  identity_matrix.row = identity_matrix.col = 3;
  mat.v[0][0] = 1, mat.v[0][1] = 1, mat.v[0][2] = 2;
  mat.v[1][0] = 1, mat.v[1][1] = 0, mat.v[1][2] = 0;
  mat.v[2][0] = 0, mat.v[2][1] = 1, mat.v[2][2] = 1;
  matrix pat;
  pat.row = 3, pat.col = 1;
  pat.v[0][0] = 1;
  pat.v[1][0] = 1;
  pat.v[2][0] = 0;
  mat = power(mat,n-1);
//  cout << mat.v[0][0] << " " << mat.v[0][1] << endl;
  pat = multiply(mat,pat);
  printf("Case %d: %lld\n",test,pat.v[0][0]);
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
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(i == j)identity_matrix.v[i][j]=1;
      else identity_matrix.v[i][j]=0;
    }
  }
  test();
  return 0;
}
