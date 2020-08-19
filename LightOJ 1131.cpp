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
struct matrix
{
  ll row, col, v[6][6];
};
ll f0,f1,f2,g0,g1,g2,a1,a2,b1,b2,c1,c2,M,q,n;
matrix identity_matrix;
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      int sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= M;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}
matrix power(matrix mat, int p) {
  if (p == 0) return identity_matrix;
  if (p == 1) return mat;
  if (p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}


void solve(int test)
{
  scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&a2,&b2,&c2,&f0,&f1,&f2,&g0,&g1,&g2,&M,&q);
  printf("Case %d:\n",test);
  while(q--)
  {

    scanf("%lld",&n);
    if(n == 0)printf("%lld %lld\n",f0%M,g0%M);
    else if(n == 1)printf("%lld %lld\n",f1%M,g1%M);
    else if(n == 2)printf("%lld %lld\n",f2%M,g2%M);
    else
    {
      matrix mat;
      mat.row = mat.col = 6;
      mat.v[0][0] = a1 , mat.v[0][1]=b1, mat.v[0][2] = 0, mat.v[0][3] = 0, mat.v[0][4] = 0, mat.v[0][5] = c1;
      mat.v[1][0] = 1, mat.v[1][1] = 0, mat.v[1][2] = 0, mat.v[1][3] = 0, mat.v[1][4] = 0, mat.v[1][5] = 0;
      mat.v[2][0] = 0, mat.v[2][1] = 1, mat.v[2][2] = 0,mat.v[2][3] = 0,mat.v[2][4] = 0,mat.v[2][5] = 0;
      mat.v[3][0] = 0, mat.v[3][1] = 0, mat.v[3][2] = c2, mat.v[3][3] = a2, mat.v[3][4] = b2, mat.v[3][5] = 0;
      mat.v[4][0] = 0, mat.v[4][1] = 0, mat.v[4][2] = 0, mat.v[4][3] = 1, mat.v[4][4] = 0, mat.v[4][5] = 0;
      mat.v[5][0] = 0,mat.v[5][1] = 0,mat.v[5][2] = 0,mat.v[5][3] = 0,mat.v[5][4] = 1,mat.v[5][5] = 0;
      matrix pat;
      pat.row = 6, pat.col = 1;
      pat.v[0][0]=f2,pat.v[1][0]=f1,pat.v[2][0]=f0;
      pat.v[3][0]=g2,pat.v[4][0]=g1,pat.v[5][0]=g0;
      mat = power(mat,n-2);
      pat = multiply(mat,pat);
      printf("%lld %lld\n",pat.v[0][0],pat.v[3][0]);
    }
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
//  freopen("o.txt","w",stdout);
  identity_matrix.row = identity_matrix.col = 6;
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      if(i == j)identity_matrix.v[i][j]=1;
      else identity_matrix.v[i][j]=0;
    }
  }
  test();
  return 0;
}
