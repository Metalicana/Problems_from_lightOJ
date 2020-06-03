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
void solve(int test)
{
  cin >> row >> col;
  int grid[row][col];
  for(int w=0;w<row;w++)
  {
    for(int q=0;q<col;q++)
    {
      scanf("%d",&grid[w][q]);
    }
  }
  int ans = 0;
  for(int w=0;w<row;w++)
  {
    for(int q=0;q<col;q++)
    {
      if((row+col-w-q)&1 )ans=ans^grid[w][q];
    }
  }
  if(ans)printf("Case %d: win\n",test);
  else printf("Case %d: lose\n",test);
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
  freopen("o.txt","w",stdout);
  test();
  return 0;
}
