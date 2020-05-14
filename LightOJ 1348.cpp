#include <bits/stdc++.h>
using namespace std;
#define sz size()
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 30005
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
//take input
//divide the tree into separate chains
//use segment tree to answer queries
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,x,y,z,size;
int chainNo,chainHead[maxn],chainPos[maxn],chainInd[maxn],chainSize[maxn],initPoint[maxn];
vector<int> mainChain;
int subsize[maxn];
int parent[maxn];
int depth[maxn];
ll cost[maxn];
ll tree[4*maxn];
int sparse[maxn][(ll)log2(maxn)+2];
vector<int>g[maxn];
//tree init
void init(int node,int b,int e)
{
  if(b == e)
  {
    //the node that has an index of b existing in the ith chain
    tree[node] = cost[mainChain[b]];
    return;
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  init(left,b,mid);
  init(right,mid+1,e);
  tree[node] = tree[left] + tree[right];
}
//tree update
void update(int node,int b,int e,int idx,ll val)
{
  if(b > idx || e < idx)return;
  if(b >= idx && e <= idx)
  {
    tree[node] = val;
    return;
  }
  int left = 2*node;
  int right = left+1;
  int mid = (b+e)/2;
  update(left,b,mid,idx,val);
  update(right,mid+1,e,idx,val);
  tree[node] = tree[left] + tree[right];
}
//tree query
ll query(int node,int b,int e,int i,int j)
{
  if(b > j || e < i)return 0;
  if(b >= i && e <= j)return tree[node];
  int left = node*2;
  int right = left+1;
  int mid = (b+e)/2;
  return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
}
//cost of going from a to b
ll totalCost(int a,int b)
{
  int idx = chainInd[a];
  int i = initPoint[idx]+chainPos[a];
  int j = initPoint[idx] + chainPos[b];
  if(chainInd[a] == chainInd[b])
  {
  //  trace2(chainPos[a],chainPos[b]
    return query(1,0,size-1,min(i,j),max(i,j));
  }
  //a to head of a

  ll ans = query(1,0,size-1,initPoint[idx],i);
  //if(parent[chainHead[idx]])
  return ans + totalCost(parent[chainHead[idx]],b);
}
//decomposing the tree
void hld(int u,int p)
{
  if(chainHead[chainNo] == -1)
  {
    chainHead[chainNo] = u;
  }
  chainInd[u] = chainNo;
  chainPos[u] = chainSize[chainNo];
  mainChain.pb(u);
  chainSize[chainNo]++;

  int ind = -1,mai = -1;
  for(int i=0; i < g[u].sz; i++)
  {
    if(subsize[g[u][i]] > mai && g[u][i]!=p)
    {
      mai = subsize[g[u][i]];
      ind = i;
    }
  }
  if(ind >= 0)hld(g[u][ind],u);
  for(int i=0;i<g[u].sz;i++)
  {
    if(i != ind && g[u][i]!=p)
    {
      chainNo++;
      hld(g[u][i],u);
    }
  }

}
//dfs to get parent and subsize
void dfs(int V,int pV,int d)
{
  int child = 0;
  parent[V] = pV;
  depth[V] = d;
  for(auto v : g[V])
  {
    if(v == pV)continue;
    dfs(v,V,d+1);
    child += subsize[v];
  }
  subsize[V] = child+1;
}
int LCA(int x,int y)
{
  if(depth[x] < depth[y])swap(x,y);
  int log  = 1;
  int next;
  while(1)
  {
    next = log+1;
    if((1<<next)>depth[x])break;
    log++;
  }
  for(int i = log; i>=0; i--)
  {
    if(depth[x] - (1 << i) >= depth[y])
    {
      x = sparse[x][i];
    }
  }
  if(x == y)return x;
  else
  {
    for (int i = log; i >= 0; i--)
    {
      if (sparse[x][i] != -1 && sparse[x][i] != sparse[y][i])
      {
        x = sparse[x][i], y = sparse[y][i];
      }

    }
    return parent[x];
  }
}
//final answer
ll finalCost(int a,int b)
{
  int dest = LCA(a,b);
//  trace2(totalCost(a,dest),totalCost(b,dest))
  return totalCost(a,dest) + totalCost(b,dest) - totalCost(dest,dest);
}
void solve(int test)
{
  scanf("%d",&n);
  for(int w=0;w<n;w++)
  {
    scanf("%lld",&cost[w]);
  }
  for(int w=0;w<n-1;w++)
  {
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  dfs(0,-1,0);
  hld(0,0);

  for(int i=0;i<n;i++)
  {
    sparse[i][0] = parent[i];
  }
  for(int j = 1; (1 << j) < n; j++)
  {
    for(int i = 0; i< n; i++)
    {
      if(sparse[i][j-1]!=-1)
      {
        sparse[i][j] = sparse[sparse[i][j-1]][j-1];
      }
    }
  }
  //trace(chainNo)
  size = 0;
  for(int w=0;w<=chainNo;w++)
  {
    initPoint[w] = size;
    //init(1,size,size+chainSize[w]-1);
    size += chainSize[w];
  }
  init(1,0,size-1);
  scanf("%d",&m);
  printf("Case %d:\n",test);
  while(m--)
  {
    scanf("%d%d%d",&x,&y,&z);
    if(x == 0)
    {
      printf("%lld\n",finalCost(y,z));
    }
    else
    {
      //trace4(chainInd[y],chainSize[chainInd[y]],chainPos[y],z)
      int idx = chainInd[y];
      update(1,0,size-1,initPoint[idx]+chainPos[y],(ll)z);
    }
  }

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int w=0;w<maxn;w++)
    {
      g[w].clear();
    }
    mainChain.clear();
    memset(chainHead,-1,sizeof chainHead);
    memset(sparse,-1,sizeof sparse);
    memset(chainSize,0,sizeof chainSize);
    chainNo = 0;
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
