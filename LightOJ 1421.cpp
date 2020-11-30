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
#define maxn 500000000
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
int I[100005];
int L1[100005],L2[100005];
vector<int>ara;
void lis(int x)
{
  I[0]=-maxn;
  for(int i=1;i<=n;i++)I[i]=maxn;
  int lisLength=0;
  for(int i=0;i <n;i++)
  {
    int low, high, mid; // variables to perform binary search
     low = 0; // minimum position where we to put data in I[]
     high = lisLength; // the maximum position
     while( low <= high )
     { // binary search to find the correct position
       mid = ( low + high ) / 2;
       if( I[mid] < ara[i] )
       low = mid + 1;
       else
       high = mid - 1;
     }
     I[low] = ara[i];
     if( lisLength < low )
     {
       lisLength=low;
       if(x==0)L1[i]=lisLength;
       else L2[i]=lisLength;
     }
     else
     {
       if(x==0) L1[i]=low;
       else L2[i]=low;
     }

  }
}
void solve(int test)
{
  scanf("%d",&n);
  ara.clear();
  for(int i=0;i<n;i++)
  {
    scanf("%d",&m);
    ara.pb(m);
  }
  lis(0);
  reverse(ara.begin(),ara.end());
  lis(1);
  int ans = 0;
  for(int i=0;i<n;i++)
  {
    //trace3(i,L1[i],L2[n-i-1])
    ans = max(ans,2*min(L1[i],L2[n-i-1])-1);
  }
  printf("Case %d: %d\n",test,ans);



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
