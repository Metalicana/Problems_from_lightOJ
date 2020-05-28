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
int m,n,row,col;
double ax,ay,az,bx,by,bz,cx,cy,cz;
double xf1,xf2,yf1,yf2,zf1,zf2;
double dst(double a,double b, double c, double d,double e, double f)
{
  return (a-b)*(a-b) + (c-d)*(c-d) + (e-f)*(e-f);
}
void solve(int test)
{
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&az,&bx,&by,&bz,&cx,&cy,&cz);
  double m1,m2,l,r;
  l = 0;
  r = 1.0;
  for(int i = 0; i < 100; i++)
  {
    m1 = l + (r-l)/3;
    m2 = r - (r-l)/3;
    xf1 = m1*ax + (1.0-m1)*bx;
    yf1 = m1*ay + (1.0 - m1)*by;
    zf1 = m1*az + (1.0 - m1)*bz;

    xf2 = m2*ax + (1.0 - m2)*bx;
    yf2 = m2*ay + (1.0 - m2)*by;
    zf2 = m2*az + (1.0 - m2)*bz;
    if(dst(xf1,cx,yf1,cy,zf1,cz) > dst(xf2,cx,yf2,cy,zf2,cz))l=m1;
    else r=m2;

  }
  double d = sqrt(dst(xf1,cx,yf1,cy,zf1,cz));
  printf("Case %d: %.10lf\n",test,d);
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
