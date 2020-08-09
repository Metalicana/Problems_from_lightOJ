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
int m,n,row,col;

void solve(int test)
{

  scanf("%d%d",&n,&m);
  queue <int> main_queue, temporary_queue;
  bool info[n+1][m+1];
  int fw[m+1],tmp;
  for(int i=1;i<=m;i++)fw[i]=0;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)info[i][j]=0;
  for(int i=1;i<=n;i++)main_queue.push(i);
  int clock = 1;
  int cur_bot = 1;
  bool k = 0;
  while(true)
  {

    //find the first person in the queue who is willing to go
    //trace(clock)
    k = 0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(info[i][j]==0)
        {
          k=1;
          break;
        }
      }
    }
    if(!k)break;

    tmp = fw[cur_bot];
    info[tmp][cur_bot]=1;
    if(tmp!=0)main_queue.push(tmp);
    if(!main_queue.empty())
    {
      while(info[main_queue.front()][cur_bot]==1)
      {
        temporary_queue.push(main_queue.front());
        main_queue.pop();
        if(main_queue.empty())break;
      }


        if(!main_queue.empty())
        {
          fw[cur_bot]=main_queue.front();
          main_queue.pop();
          while(!main_queue.empty())
          {
            temporary_queue.push(main_queue.front());
            main_queue.pop();
          }
          while(!temporary_queue.empty())
          {
            main_queue.push(temporary_queue.front());
            temporary_queue.pop();
          }
        }
        else
        {
          fw[cur_bot]=0;
          while(!temporary_queue.empty())
          {
            main_queue.push(temporary_queue.front());
            temporary_queue.pop();
          }
        }
    }
      cur_bot++;
      if(cur_bot>m)cur_bot=1;
      clock++;
  }
  printf("Case %d: %d\n",test,clock*5-5);

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
