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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,k;
int dest[100005];
int ara[100005];
int memo[100005];
int tree[400005];
void init(int node,int b,int e)
{
  if(b == e)
  {
    if(b==n)tree[node]=0;
    else tree[node]=200000;
    return;
  }
  int left = 2*node;
  int right = left+1;
  init(left,b,(b+e)/2);
  init(right,1+(b+e)/2,e);
  tree[node] = min(tree[left],tree[right]);
}
void update(int node,int b,int e,int i,int x)
{
  if(b>i || e< i)return;
  if(b==i&&e==i)
  {
    tree[node]=x;
    return;
  }
  update(2*node,b,(b+e)/2,i,x);
  update(2*node+1,1+(b+e)/2,e,i,x);
  tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node,int b,int e,int i,int j)
{
  if(b > j || e < i)return 200000;
  if(b >= i && e <= j)
  {
    return tree[node];
  }
  int p1 = query(node*2,b,(b+e)/2,i,j);
  int p2 = query(1+node*2,1+(b+e)/2,e,i,j);
  return min(p1,p2);
}
void solve(int test)
{
  memset(memo,-1,sizeof memo);
  init(1,0,n);
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++)scanf("%d",&ara[i]);
  sort(ara,ara+n);
  int i = 0;
  int j = 2;
  int cnt;
  int mid_1,mid_2;
  while(i < n)
  {
    if(j>= n)
    {
      for(int q=i;q<j;q++)
      {
        dest[q]=j-1;
      }
      break;
    }
    if(ara[j]-k -ara[i] <= k )
    {
      j++;
    }
    else
    {
      dest[i]=j-1;
      i++;
    }

  }
  for(int i=n-1;i>=0;i--)
  {
    if(dest[i]+1 < i+3)
    {
      memo[i]=200000;
      update(1,0,n,i,memo[i]);
    }
    else
    {
      memo[i] = 1+query(1,0,n,i+3,dest[i]+1);
      update(1,0,n,i,memo[i]);
    }
  }
  if(memo[0]>=200000)printf("Case %d: -1\n",test);
  else printf("Case %d: %d\n",test,memo[0]);
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
