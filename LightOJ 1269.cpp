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
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};

struct node
{
  node *left;
  node *right;
  node()
  {
    left = NULL;
    right = NULL;
  }
};
int m,n,row,col,dig,k,maxVal,minVal,point;
int ara[50006];
int xxor[50006];
int xxorCopy[50006];
vector<int>nums[50006];
vector<pair<node*,int> >deepPoints;
struct trie
{
  node *root;
  trie()
  {
    root = NULL;
  }
  void registerIt(int j)
  {
    int i;
    if(root == NULL)root=new node();
    node *cur = root;
    node *noya;
    rep(i,dig)
    {
      //printf("%d",nums[j][i]);
      if(nums[j][i])
      {
        if(cur->right ==NULL)
        {
          noya = new node();
          cur->right = noya;
          cur = noya;
        }
        else cur=cur->right;
      }
      else
      {
        if(cur->left == NULL)
        {
          noya = new node();
          cur->left = noya;
          cur = noya;
        }
        else cur = cur->left;
      }
    }
    //printf("\n");
  }
  int dfsMax(node *c1,node *c2,int i)
  {
    //ith level wiint yeild 2^(dig-i-1) if they mismatch
    int p = 0;
    if(c1->left== NULL && c1->right==NULL)//leaf
    {
      return 0;
    }
    else
    {
      if((c1->left != NULL && c2->right!= NULL) && (c1->right!= NULL&&c2->left!= NULL) )
      {
        //trace(i)
        p = max(p,(1<<(dig-i-1))+dfsMax(c1->left,c2->right,i+1));
        p = max(p,(1<<(dig-i-1))+dfsMax(c1->right,c2->left,i+1));
      }
      else if(c1->left != NULL && c2->right!= NULL)
      {
        p = max(p,(1<<(dig-i-1))+dfsMax(c1->left,c2->right,i+1));
      }
      else if(c1->right!= NULL && c2->left!= NULL)
      {
        p = max(p,(1<<(dig-i-1))+dfsMax(c1->right,c2->left,i+1));
      }
      else
      {
        if(c1->left != NULL && c2->left != NULL)
        {
          p = max(p,0 + dfsMax(c1->left,c2->left,i+1));
        }
        else if(c1->right!= NULL && c2->right!= NULL)
        {
          p = max(p,0+dfsMax(c1->right,c2->right,i+1));
        }
      }
    }
    return p;
  }
  int dfsMin(node* c1,node* c2,int i)
  {
    int p = INT_MAX;
    if(c1->left== 0&& c1->right==0)//leaf
    {
      //trace2(c2->left,c2->right)
      return 0;
    }
    else
    {
      if(c1->left != NULL && c2->left != NULL && c1->right!=NULL && c2->right!=NULL )
      {
        p = min(p,0 + dfsMin(c1->left,c2->left,i+1));
        p = min(p,0+dfsMin(c1->right,c2->right,i+1));
      }
      else if(c1->left != NULL && c2->left != NULL)
      {
        p = min(p,0 + dfsMin(c1->left,c2->left,i+1));
      }
      else if(c1->right!=NULL && c2->right!=NULL)
      {
        p = min(p,0+dfsMin(c1->right,c2->right,i+1));
      }
      else
      {
        if(c1->left != NULL && c2->right!=NULL)
        {
          p = min(p,(1<<(dig-i-1))+dfsMin(c1->left,c2->right,i+1));
        }
        else if(c1->right!=NULL&&c2->left!=NULL)
        {
          p = min(p,(1<<(dig-i-1))+dfsMin(c1->right,c2->left,i+1));
        }
      }
    }
    return p;
  }

  void dfs(node *cur,int dep)
  {
    if(cur->left != NULL && cur->right != NULL)
    deepPoints.pb(mp(cur,dep));
    if(cur->left != NULL)dfs(cur->left,dep+1);
    if(cur->right!= NULL)dfs(cur->right,dep+1);
  }
  void del(node *cur)
  {
    if(cur==NULL)return;
    if(cur->left != NULL)
    {
      del(cur->left);
    }
    if(cur->right != NULL)
    {
      del(cur->right);
    }
    delete(cur);

  }
  void clear()
  {
    del(root);
  }


};
bool cmp(pair<node*,int> a, pair<node*,int> b)
{
  return a.second>b.second;
}
void solve(int test)
{
  int i,j;
  scanf("%d",&n);
  rep(i,n)scanf("%d",&ara[i]);
  if(n ==1 )printf("Case %d: %d %d\n",test,ara[0],ara[0]);
  else
  {
    trie tree;
    xxor[0]=0;
    xxorCopy[0]=0;
    xxor[1]=ara[0]^ara[1];
    xxorCopy[1]=xxor[1];
    m=xxor[1];
    for(i=2;i<n;i++)
    {
      xxor[i]=xxor[i-1]^ara[i];
      m=max(m,xxor[i]);
      xxorCopy[i]=xxor[i];
    }
    dig = log2(m)+1;

    rep(i,n)
    {
      rep(j,dig)
      {
        nums[i].pb(xxor[i]%2);
        xxor[i]/=2;
      }
      reverse(nums[i].begin(),nums[i].end());
    }
    rep(i,n)
    {
      tree.registerIt(i);
    }
    //everyone is in the trie
    //run a loop that finds the first split
    node *cur = tree.root;
    k=0;
    maxVal = 0;
    while(1)
    {
      if(cur->left != NULL && cur->right != NULL)break;
      else if(cur->left != NULL)cur=cur->left;
      else cur=cur->right;
      //make kth digit 0
      k++;
    }
    //find the max number using split from i
    maxVal = ((1<<(dig-k-1))) + tree.dfsMax(cur->left,cur->right,k+1);
    //trace(maxVal)
  //  tree.clear();
    sort(xxorCopy,xxorCopy+n);
    int tt = 0;
    rep(i,n-1)
    {
      if(xxorCopy[i] == xxorCopy[i+1])
      {
        tt=1;
        break;
      }
    }
    minVal = INT_MAX;
    if(tt)minVal=0;
    else
    {
      tree.dfs(tree.root,0);
      sort(deepPoints.begin(),deepPoints.end(),cmp);
      point = deepPoints[0].y;
      //trace(point)
      for(auto x : deepPoints)
      {
        minVal = min(minVal,((1 <<(dig-x.y-1))+tree.dfsMin(x.x->left,x.x->right,x.y+1)));
        if(x.y != point)break;
      }
    }
    rep(i,n)
    {
      if(ara[i]>maxVal)maxVal = ara[i];
      if(ara[i]<minVal)minVal = ara[i];
    }
    printf("Case %d: %d %d\n",test,maxVal,minVal);
    tree.clear();

  }

}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    for(int i=0;i<50006;i++)nums[i].clear();
    deepPoints.clear();
    solve(test);
  }
}
int main()
{
  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
