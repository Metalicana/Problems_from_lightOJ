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
#define MN 55
#define MS 100001
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,ans;
string s,line;
int gid(const char &c){
  if(c >= 'A' and c <= 'Z') return c - 'A';
  return (c - 'a') + 26;
}

struct trie{
  struct node{
    int c;
    int a[MN];
  };

  node tree[MS];
  void clear(){
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  int nodes;

  void init(){
    nodes = 0;
    clear();
  }

  int add(const string &s, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = gid(s[i]);
      if(tree[cur_node].a[id] == -1){
        if(query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if(!query) tree[cur_node].c++;
    return tree[cur_node].c;
  }

};
trie tree;
void solve(int test)
{
  scanf("%d",&n);
  //word sample;
  tree.init();
  for(int w=0;w<n;w++)
  {
    cin >> s;
    if(s.sz > 2)
    sort(s.begin()+1,s.end()-1);
    tree.add(s);
  }

  scanf("%d",&m);
  printf("Case %d:\n",test);
  getline(cin,line);
  while(m--)
  {
      getline(cin,line);
      ans = 1;
      stringstream ss(line);
      while(ss>>line){

        s = line;
        if(s.sz > 2)
        sort(s.begin()+1,s.end()-1);

        ans = ans*tree.add(s,1);
        if(ans == 0)break;
      }
      printf("%d\n",ans);
  }
  //tree.err();
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
