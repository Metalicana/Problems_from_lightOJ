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
#define lim 262144
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y;
int tree[4*lim];
int lazy[4*lim];
void update(int node,int b,int e,int i,int j,int x)
{
  if(lazy[node]!=0)
  {
    if(b != e)//not leaf
    {
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
    }
    else tree[node] = lazy[node];
    lazy[node] = 0;
  }
  if(b > j || e < i)return;
  if(b >= i && e <= j)
  {
    if(b == e)tree[node] = x;
    else
    {
      lazy[node] = x;
    }
    return;
  }
  int left  = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  update(left, b,mid,i,j,x);
  update(right, mid+1,e,i,j,x);
}
void init(int node,int b,int e)
{
  if(lazy[node]!=0)
  {
    if(b != e)//not leaf
    {
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
    }
    else tree[node] = lazy[node];
    lazy[node] = 0;
  }
  if(b == e)
  {
    return;
  }
  int left  = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  init(left,b,mid);
  init(right,mid+1,e);
}
void solve(int test)
{
  memset(tree,0,sizeof tree);
  memset(lazy,0,sizeof lazy);
  scanf("%d",&n);
  for(int w=0;w<n;w++)
  {
    scanf("%d%d",&x,&y);
    update(1,0,lim-1,x-1,y-1,w+1);
  }
  set<int> sex;
  init(1,0,lim-1);
  for(int w=lim,q=0;q<n*2;q++, w++)
  {
    if(tree[w] == 0)continue;
    else sex.insert(tree[w]);
  }
  printf("Case %d: %d\n",test,sex.size());

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
