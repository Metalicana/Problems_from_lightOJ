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
#define TEST cout << "sex\n";
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,d;
pair<double,double> ara[20005];
bool cmp(pair<double,double> a, pair<double,double> b)
{
  return (a.x - b.x) >= 0.0000000001;
}
void solve(int test)
{
  scanf("%d%d",&n,&d);
  vector<pair <double,int> >sexvideo;
  for(int i=0;i<n;i++)
  {
    scanf("%lf%lf",&ara[i].x,&ara[i].y);
  }
  double left = 0;
  double right = 1.0;
  double mid;
  for(int i=0;i<25;i++)
  {

    mid = (left+right)/2.0;
    sexvideo.clear();

    for(int i=0;i<n;i++)
    {
      sexvideo.pb(mp(ara[i].x - mid*ara[i].y,i));
    }
    sort(sexvideo.begin(),sexvideo.end(),cmp);
    double gosol = 0.0;
    for(int i=0;i<n-d;i++)
    {
      gosol+=sexvideo[i].x;
    }
  //  trace2(gosol,mid)
    if(gosol>0.0)left=mid;
    else right=mid;
  }
  double sex = 0.0;
  double video = 0.0;
  for(int i=0;i < n-d; i++)
  {
    sex += ara[sexvideo[i].y].x;
    video += ara[sexvideo[i].y].y;
  }
  printf("Case %d: %.10lf\n",test,100.0*sex/video);

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
