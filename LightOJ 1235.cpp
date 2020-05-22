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
ll m,n,row,col,sum;
ll lim;

int pir[2][4] = {{1,1,2,2},{1,2,1,2}};
ll A[20];
ll power(ll b,ll p)
{
  if( p == 0)return 1;
  if(p == 1)return b;
  ll j = power(b,p/2);
  if(p%2==0)return j*j;
  return j*j*b;
}
ll ara[19683+6];
ll bara[19683+6];
void solve(int test)
{
  scanf("%lld%lld",&n,&m);
  int j,left,right,mid;
  for(int w=0;w<n;w++)scanf("%lld",&A[w]);
  lim = power(3,n/2);
  int flick = 0;
  for(int i=0; i < lim; i++)
  {
    j = i;
    sum = 0;
    for(int k=0;k<(n/2);k++)
    {
      if( j%3 == 1)sum += A[k];
      else if(j% 3 == 2) sum += A[k]*2;
      j = j/3;
    }
    ara[i] = sum;
  }
    lim = power(3,n-n/2);
    for(int i=0; i < lim; i++)
    {
      j = i;
      sum = 0;
      for(int k=n/2;k<n;k++)
      {
        if( j%3 == 1)sum += A[k];
        else if(j% 3 == 2) sum += A[k]*2;
        j = j/3;
      }
      bara[i] = sum;
    }
      ll lim1 = power(3,n/2);
      ll lim2 = power(3,n-n/2);
      sort(ara,ara+lim1);
      sort(bara,bara+lim2);
        for(int i=0; i < lim1; i++)
        {
          left = 0;
          right = lim2-1;
          while(left < right)
          {
            if(left + 1 == right)
            {
              if(ara[i] + bara[left]== m ||
                ara[i] + bara[right] == m)flick = 1;
              break;
            }
            mid = (left+right)/2;
            if(ara[i] + bara[mid] < m)left = mid;
            else if(ara[i] + bara[mid] > m)right = mid;
            else
            {
              flick = 1;
              break;
            }
          }
          if(flick)break;
        }

      if(flick )printf("Case %d: Yes\n",test);
      else printf("Case %d: No\n",test);

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
  test();
  return 0;
}
