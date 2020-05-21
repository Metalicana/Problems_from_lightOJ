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
int grundy[10005];
set <int> s;
void solve(int test)
{
  scanf("%d",&n);
  m = 0;
  for(int w=0;w<n;w++)
  {
    scanf("%d",&row);
    m = (grundy[row]^m);
  }
  if(m==0)printf("Case %d: Bob\n",test);
  else printf("Case %d: Alice\n",test);

}
void test()
{

  for(int w=3;w<=10000;w++)
  {
    row = 0;
    s.clear();
    for(int q=1;q<=w/2;q++)
    {
      if(q != w-q){row = (grundy[q]^grundy[w-q]);
      s.insert(row);}
    }
    int i = 0;
    int a = 0;
    for(auto x: s)
    {
      if(x != i)
      {
        grundy[w] = i;
        a = 1;
        break;
      }
      i++;
    }
    if(!a)grundy[w] = i;
  }
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
