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
#define lim ((1<<17))
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
int ara[100006];
int tree[4*lim];
void init(int node,int b,int e)
{
  if(b == e)
  {
    if(node >= lim && node < lim + n)
    {
      tree[node] = 1;
    }
    else tree[node] = 0;
    return;
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  init(left,b,mid);
  init(right,mid+1,e);
  tree[node] = tree[left]+tree[right];
}

void solve(int test)
{

  scanf("%d",&n);
  init(1,0,lim-1);
  int toFind;
  int node,ans;
  for(int w=0;w<n;w++)scanf("%d",&ara[w]);

  for(int w=n-1;w>=0;w--)
  {
    toFind = ara[w]+1;
    //from the root, go to the leaf such that it's the toFind'th node
    node = 1;
    while(node < lim)
    {
      if(tree[node*2] >= toFind)
      {
        node = node*2;
      }
      else
      {
        toFind = toFind - tree[node*2];
        node =  2*node+1;
      }
    }
    //trace2(n,n-node+lim)
    if(w == 0)ans = n-node+lim;
    while(node!=0)
    {
      tree[node]--;
      node/=2;
    }
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
