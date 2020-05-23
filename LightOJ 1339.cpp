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
int m,n,row,col,q,c,x,y;
int chainIdx[100005];
int chainHead[100005];
int chainTail[100005];
int ara[100005];
int tree[4*100005];
void init(int node,int b,int e)
{
  if(b == e)
  {
    tree[node] = 1;
    return;
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  init(left,b,mid);
  init(right,mid+1,e);
  if(chainIdx[mid] != chainIdx[mid+1])tree[node] = max(tree[left],tree[right]);
  else
  {
    tree[node] = max(tree[left],tree[right]);
    tree[node] = max(tree[node],min(e,chainTail[chainIdx[mid]])-max(b,chainHead[chainIdx[mid]])+1 );
  }
//  trace4(node,b,e,tree[node])

}
int query(int node,int b,int e,int i, int j)
{
  //cout << node << endl;
  if( b > j || e < i)return -100;
  if(b >= i && e <= j)return tree[node];
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  int p1 = query(left,b,mid,i,j);
  int p2 = query(right,mid+1,e,i,j);
  if(chainIdx[mid] != chainIdx[mid+1])return max(p1,p2);
  else
  {
      int x = max(p1,p2);
      return max(x,min(j,chainTail[chainIdx[mid]])-max(i,chainHead[chainIdx[mid]])+1 );
      return x;

  }

}
void solve(int test)
{
    scanf("%d%d%d",&n,&c,&q);
    for(int w=0;w<n;w++)
    {
      scanf("%d",&ara[w]);
    }
    m = 1;
    chainHead[0] = 1;
    chainIdx[0] = 1;
    for(int w=0;w<n-1;w++)
    {
      if(ara[w]!=ara[w+1])
      {
        chainIdx[w] = m;
        chainTail[m] = w;
        chainHead[m+1] = w+1;
        m++;
      }
      else
      {
        chainIdx[w] = m;
      }
    }
    if(ara[n-1] != ara[n-2])
    {
      chainIdx[n-1] = m;
      chainTail[m] = n-1;
    }
    else
    {
       chainIdx[n-1] = m;
       chainTail[m] = n-1;
    }
    init(1,0,n-1);

    printf("Case %d:\n",test);
    for(int w=0;w<q;w++)
    {
      scanf("%d%d",&x,&y);
      printf("%d\n",query(1,0,n-1,x-1,y-1));

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
