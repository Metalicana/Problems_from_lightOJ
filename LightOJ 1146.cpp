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
double ax,ay,bx,by,cx,cy,dx,dy;
double xf1,xf2,xf3,xf4,yf1,yf2,yf3,yf4,d1,d2;
double dst(double xf,double yf,double xs, double ys)
{
  return (xf-xs)*(xf-xs) + (yf-ys)*(yf-ys);
}
void solve(int test)
{
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
  double l,r,m1,m2;

  l = 0.0;
  r = 1.0;
  for(int i = 0; i < 100; i++)
  {
    m1 = l + (r-l)/3;
    m2  = r - (r-l)/3;
    xf1 = ax*m1 + (1.0 - m1)*bx;
    yf1 = ay*m1 + (1.0 - m1)*by;
    xf2 = cx*m1 + (1.0 - m1)*dx;
    yf2 = cy*m1 + (1.0 - m1)*dy;
    d1 = dst(xf1,yf1,xf2,yf2);
    xf3 = ax*m2 + (1.0 - m2)*bx;
    yf3 = ay*m2 + (1.0 - m2)*by;
    xf4 = cx*m2 + (1.0 - m2)*dx;
    yf4 = cy*m2 + (1.0 - m2)*dy;
    d2 = dst(xf3,yf3,xf4,yf4);
    if(d1 > d2)l=m1;
    else r = m2;
  }
  d1 = sqrt(d1);
  printf("Case %d: %.10lf\n",test,d1);
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
