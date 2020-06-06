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
double ax,ay,bx,by,ar,br;
void solve(int test)
{
  scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&ar,&bx,&by,&br);
  if(ar > br)
  {
    swap(ar,br);
    swap(ax,bx);
    swap(ay,by);
  }
  double d = sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
//trace(d)
  if(d >=ar+br)//touching to not touching
  {
    printf("Case %d: 0\n",test);
  }
  else if(d <= ar + br && d > fabs(ar-br))
  {
    double a = acos((ar*ar+d*d-br*br) / (2.00*ar*d));
    double b = acos((br*br+d*d-ar*ar) / (2.00*br*d));
    double ans = .5 *(ar*ar*(2.0*a) - ar*ar*sin(2.0*a) + br*br*(2.0*b) - br*br*sin(2.0*b));
    printf("Case %d: %.10lf\n",test,ans);
  }
  else printf("Case %d: %.10lf\n",test,pi*ar*ar);
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
