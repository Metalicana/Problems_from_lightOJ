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
int m,n,row,col,midi,digit_count;
vector<int>dig;
ll a,b;
int memo[18][2];
int power(int b,int p)
{
  if(p == 0)return 1;
  if(p == 1)return b;
  int x = power(b,p/2);
  if(p%2==0)return x*x;
  return x*x*b;
}
int sth(int a)
{
  return power(10,(a+1)/2);
}
int dp(int i,int tight)
{
  if(i >= midi)
  {
    if(tight==0)return 1;
    else
    {

      for(int p=(digit_count-1)/2,q=(digit_count)/2;p>=0;p--,q++)
      {
        if(dig[p]<dig[q])
        {
          return 1;
        }
        else if(dig[p]>dig[q])return 0;
      }
      return 1;
    }
  }
  if(memo[i][tight] != -1 && tight == 0)return memo[i][tight];
  int k = 9;
  if(tight == 1)k = dig[i];
  int p=0;
  int ans = 0;
  for(int j=0;j<=k;j++)
  {
    if(j == 0 && i == 0)j++;
    if(j > k)break;
    p = (dig[i] == j)?tight:0;
    if(p == 0 )
    {
      ans = ans + sth(digit_count-2*(i+1));
    }
    else
    {
      ans+=dp(i+1,p);
    }
  }
  if(tight == 0)memo[i][tight]=ans;
  return ans;
}
int pls(int i)
{
  return 9*power(10,(i-1)/2);
}
void solve(int test)
{
  scanf("%lld %lld",&a,&b);
  if(a > b)swap(a,b);
  a--;

  memset(memo,-1,sizeof memo);

  dig.clear();
  while(b>0)dig.pb(b%10),b/=10;
  reverse(dig.begin(),dig.end());

  digit_count = dig.sz;
  midi = (digit_count+1)/2;
  int dancer = 1;
  for(int i=1;i<digit_count;i++)dancer+=pls(i);
  int mancer = dp(0,1)+dancer;


  if(a == -1)
  {
    printf("Case %d: %d\n",test,mancer);
  }
  else if(a == 0)
  {
    printf("Case %d: %d\n",test,mancer-1);
  }
  else
  {
    memset(memo,-1,sizeof memo);
    dig.clear();
    while(a>0)dig.pb(a%10),a/=10;
    reverse(dig.begin(),dig.end());
    digit_count = dig.sz;
    midi = (digit_count+1)/2;
    int cancer = 1;
    for(int i=1;i<digit_count;i++)cancer+=pls(i);
    int bancer = dp(0,1)+cancer;
    printf("Case %d: %d\n",test,mancer-bancer);
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
//  freopen("oss.txt","w",stdout);
  test();
  return 0;
}
