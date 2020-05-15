#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sz size()
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100005
#define mod 1000000007
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,q,p,s,nd,num,size;
int cost[maxn];
vector <int> g[maxn];
int chainNo,chainHead[maxn],chainPos[maxn],chainInd[maxn],chainSize[maxn],initPoint[maxn];
vector<int> mainChain;
int subsize[maxn];
int parent[maxn];
int depth[maxn];
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
int query(int nd,int num)
{
  int idx = chainInd[nd];
  int left = 0;
  int right = chainPos[nd];
  int mid,ans,temp;
  int st = initPoint[idx];
  ans = -1;
  if(left == right)
  {
    if(idx == 0 && cost[0] >= num)return 0;
    else if(idx == 0 && cost[0] < num)return -1;
    ans = mainChain[st];
    if(cost[mainChain[st]] < num)return -1;
    temp = query(parent[ans],num);
    if(temp!=-1)return temp;
    return ans;
  }
  while(left < right)
  {
    mid = (left+right)/2;
    if(left + 1 == right)
    {
      if(cost[mainChain[st+left]] >= num)ans=left;
      else if(cost[mainChain[st+right]] >= num)ans = right;
      break;
    }
    if(cost[mainChain[st + mid]] > num)right = mid;
    else left = mid;
  }
  if(ans == -1)return -1;
  if(chainHead[idx] != mainChain[ans+st])return mainChain[ans+st];
  else
  {
    if(idx == 0)return 0;
    else
    {
      temp = query(parent[mainChain[ans+st]],num);
      if(temp!=-1)return temp;
      return mainChain[ans+st];
    }
  }
  //if ans is the head, then I should go to the next chain and query there
}
void solve(int test)
{
  scanf("%d%d",&n,&q);
  cost[0] = 1;
  for(int w=1;w<n;w++)
  {
    scanf("%d%d",&p,&s);
    g[w].pb(p);
    g[p].pb(w);
    cost[w] = s;
  }
  //hld the crap out of this
  dfs(0,-1,0);
  hld(0,0);
  size = 0;
  for(int w=0;w<=chainNo;w++)
  {
    initPoint[w] = size;
    size += chainSize[w];
  }
  printf("Case %d:\n",test);
  while(q--)
  {
    scanf("%d%d",&nd,&num);
    printf("%d\n",query(nd,num));
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
  //  memset(sparse,-1,sizeof sparse);
    memset(chainSize,0,sizeof chainSize);
    chainNo = 0;
    solve(test);
  }
}
int main()
{
  test();
  return 0;
}
