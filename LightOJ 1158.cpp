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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col,d,k;
int memo[1024][1000];
char s[10];
int fact[11];
map<int,int>dig;
bool check(int mask,int i)
{
  return ((1<<i)&mask);
}
int Set(int mask,int i)
{
  return mask | (1<<i);
}
int dp(int mask,int x)
{
  if(mask == (1<<n)-1)return x==0;
  if(memo[mask][x]!=-1)return memo[mask][x];
  int p = 0;
  for(int i=0;i<n;i++)
  {
    if(!check(mask,i))p+=dp(Set(mask,i),(x*10 + (s[i]-'0'))%d);
  }
  memo[mask][x]=p;
  return memo[mask][x];
}

void solve(int test)
{
  memset(memo,-1,sizeof memo);
  dig.clear();
  scanf("%s%d",s,&d);
  n=strlen(s);
  k=1;
  for(int i=0;i<n;i++)
  {
    dig[s[i]-'0']++;
  }
  for(int i=0;i<10;i++)k = k * fact[dig[i]];
  m = dp(0,0)/k;
  printf("Case %d: %d\n",test,m);
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
  fact[0]=1;
  for(int i=1;i<=10;i++)fact[i]=i*fact[i-1];
  test();
  return 0;
}
