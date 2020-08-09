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
int m,n,row,col;
struct task
{
  int val;
  bool dst;//dst == 0 start 1 end
}pro[50005*2];
bool cmp(task a, task b)
{
  if(a.val == b.val)
  {
    return !a.dst;
  }
  else return a.val < b.val;
}
void solve(int test)
{
  scanf("%d",&n);
  for(int i=0;i<2*n;i++)
  {
    scanf("%d",&pro[i].val);
    if(i%2==0)pro[i].dst=0;
    else pro[i].dst=1;
  }
  sort(pro,pro+2*n,cmp);
  int free=0,busy=0;
  for(int i=0;i<2*n;i++)
  {
    if(pro[i].dst == 0)
    {
      if(free == 0)
      {
        busy++;
      }
      else
      {
        free--;
        busy++;
      }
    }
    else
    {
      busy--;
      free++;
    }
  }
  printf("Case %d: %d\n",test,free);

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
