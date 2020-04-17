#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define maxn 100000
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
ll m,n,row,col,x,y;
double sex[100006];
void solve(int test)
{
  scanf("%d",&n);
  if(n <=2)printf("Case %d: %d\n",test,1);
  else if(n <= 3)printf("Case %d: %d\n",test,2);
  else
  {
    int left = 1;
    int right = n-1;
    int x;
    while(left <= right)
    {
      x = (left+right)/2;
      if(left==right)
      {
        x=left;
        break;
      }
      if(left+1 == right)
      {
        if((double)right >= (log10(2.0) + sex[n] - sex[n-right])/log10((double)n))
        {
          x = right;
          break;
        }
        else x = left;
        break;
      }
      if((double)x >= (log10(2.0) + sex[n] - sex[n-x])/log10((double)n))right=x;
      else left = x;
    }


    printf("Case %d: %d\n",test,x-1);
  }
}
void test()
{
  int t;
  sex[1] = 0.0;
  for(int i=2;i<100001;i++)
  {
    sex[i] = sex[i-1] + log10(i);
  }
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
