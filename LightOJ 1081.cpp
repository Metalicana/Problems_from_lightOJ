#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,a,b,c;
int g[505][505];
int tree[505][4*505];
void init(int i,int node,int b ,int e)
{
  if(b == e)
  {
    tree[i][node] = g[i][b];
    return;
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  init(i,left,b,mid);
  init(i,right, mid+1,e);
  tree[i][node] = max(tree[i][left],tree[i][right]);
}
int query(int ii,int node,int b,int e,int i,int j)
{
  if(b > j || e < i)return -1;
  if(b >= i && e <= j)return tree[ii][node];
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  int p1 = query(ii,left,b,mid,i,j);
  int p2 = query(ii,right,mid+1,e,i,j);
  return max(p1,p2);
}
void solve(int test)
{
  scanf("%d%d",&n,&m);
  for(int w=0;w<n;w++)
  {
    for(int q=0;q<n;q++)scanf("%d",&g[w][q]);
  }
  printf("Case %d:\n",test);
  for(int w=0;w<n;w++)init(w,1,0,n-1);
  row = -1;
  for(int w=0;w<m;w++)
  {
    scanf("%d%d%d",&a,&b,&c);
    row = -1;
    for(int i=a-1;i<=a+c-2;i++)
    {
      row = max(row, query(i,1,0,n-1,b-1,b+c-2));
    }
    printf("%d\n",row);
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
  test();
  return 0;
}
