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
bool check(int mask,int i){return ((1<<i)&mask);}
int Set(int mask,int i){return mask | (1<<i);}
ll add(ll a, ll b)
{
  if(a+b<MOD)return a+b;
  return (a+b)%MOD;
}
ll mul(ll a, ll b)
{
  if(a*b < MOD)return a*b;
  return (a*b)%MOD;
}
int tree[2][4*1003];
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,q,x,y,xs,xf,ys,yf;
int baby_tree[(1<<11)+10][(1<<11)+10];

// a number node, represents a range of xi to xj
void update(int master_node,int baby_node, int b,int e,int i)
{
  if(b> i || e < i)return;
  if(b>=i&&e<=i)
  {
    baby_tree[master_node][baby_node]=1;
    return;
  }
  int l = baby_node*2;
  int r = l+1;
  int m = (b+e)/2;
  update(master_node,l,b,m,i);
  update(master_node,r,m+1,e,i);
  baby_tree[master_node][baby_node] = baby_tree[master_node][l] + baby_tree[master_node][r];
}
void treesum(int node,int pode)
{
  if(pode > 1023)return;
  baby_tree[node][pode] = baby_tree[node*2][pode]+baby_tree[1+2*node][pode];
  treesum(node,pode*2);
  treesum(node,pode*2+1);
}
int find_node(int node,int b,int e,int i)
{
  if(b> i || e < i)return -1;
  if(b>=i&&e<=i)
  {
    return node;
  }
  int l = node*2;
  int r = l+1;
  int m = (b+e)/2;
  int p1 = find_node(l,b,m,i);
  int p2 =find_node(r,m+1,e,i);
  if(p1 !=-1)return p1;
  return p2;
}
void update_master(int node, int b,int e,int i,int j)
{

  if(b>i || e<i)return;
  if(b>=i&&e<=i)
  {
    //trace(node)
    update(node,1,0,1000,j);
    return;
  }
  int l = node*2;
  int r = l+1;
  int m = (b+e)/2;
  update_master(l,b,m,i,j);
  update_master(r,m+1,e,i,j);
  //sum all baby_tree[node][..] = baby_tree[l][...] + baby[R][...]
  //treesum(node,1);
  int k = find_node(1,0,1000,j);
  while(k!=0)
  {
    baby_tree[node][k] = baby_tree[l][k] + baby_tree[r][k];
    k/=2;
  }
}

int query(int master_node,int baby_node,int b,int e,int i,int j)
{
  if(b> j || e < i)return 0;
  if(b>=i&&e<=j)
  {
    return baby_tree[master_node][baby_node];
  }
  int l = baby_node*2;
  int r = l+1;
  int m = (b+e)/2;

  int p1 = query(master_node,l,b,m,i,j);
  int p2 = query(master_node,r,m+1,e,i,j);
  return p1+p2;
}
int master_query(int node,int b,int e,int xf,int xs,int yf,int ys)
{
  if(b>xs||e<xf)return 0;
  if(b>=xf&&e<=xs)
  {
    //trace2(node,query(node,1,0,1000,yf,ys))
    return query(node,1,0,1000,yf,ys);
  }
  int l = node*2;
  int r = l+1;
  int m = (b+e)/2;
  int p1 = master_query(l,b,m,xf,xs,yf,ys);
  int p2 = master_query(r,m+1,e,xf,xs,yf,ys);
  return p1+p2;
}
void solve(int test)
{
  scanf("%d",&q);
  memset(baby_tree,0,sizeof baby_tree);
  int base = (1<<10);
  printf("Case %d:\n",test);
  while(q--)
  {
    scanf("%d",&m);
    if(m == 0)
    {
      scanf("%d%d",&x,&y);
      update_master(1,0,1000,x,y);
    }
    else
    {
      scanf("%d%d%d%d",&xf,&yf,&xs,&ys);

      printf("%d\n",master_query(1,0,1000,xf,xs,yf,ys));
    }
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
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
//1025
