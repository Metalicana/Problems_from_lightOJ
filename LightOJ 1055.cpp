
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
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
struct hecc
{
  pii a,b,c;
};
int m,n,row,col,k;
int vis[1000006],d[1000006];
pii person[3];
pii dest[3];
char g[10][10];
int am,bm,cm;

hecc lol,a;
hecc shuffle1[6],shuffle2[6];
int tax,tay,tbx,tby,tcx,tcy;
int rectify(int shuorerBaccha)
{

  if(shuorerBaccha<0)return shuorerBaccha+1;
  else if(shuorerBaccha>=n)return shuorerBaccha-1;
  return shuorerBaccha;
}
int craig(hecc a)
{
  return a.a.x*100000+a.a.y*10000+a.b.x*1000+a.b.y*100+a.c.x*10+a.c.y;
}
void shuff(hecc sexVideo[], hecc CHOP)
{
  sexVideo[0]=CHOP;//abc
  swap(CHOP.b,CHOP.c);//acb
  sexVideo[1]=CHOP;//acb
  swap(CHOP.b,CHOP.c);//abc
  swap(CHOP.a,CHOP.b);//bac
  sexVideo[2]=CHOP;//bac
  swap(CHOP.b,CHOP.c);//bca
  sexVideo[3]=CHOP;//bca
  swap(CHOP.a,CHOP.c);//acb
  swap(CHOP.a,CHOP.b);//cab
  sexVideo[4]=CHOP;//cab
  swap(CHOP.b,CHOP.c);//cba
  sexVideo[5]=CHOP;
}
bool fall(pii a, pii b)
{
  return a.x==b.x&&a.y==b.y;
}
void solve(int test)
{
  memset(vis,0,sizeof vis);
  scanf("%d",&n);
  k=0;

  for(int i=0;i<n;i++)
  {
    scanf("%s",g[i]);
    for(int j=0;j<n;j++)
    {
      if(g[i][j] == 'X')dest[k++]=mp(i,j);
      else if(g[i][j]!='.'&&g[i][j]!='#')person[g[i][j]-'A']=mp(i,j);
    }
  }
  queue<hecc> q;
  a.a.x= person[0].x, a.a.y = person[0].y;
  a.b.x = person[1].x, a.b.y = person[1].y;
  a.c.x = person[2].x, a.c.y = person[2].y;
  shuff(shuffle1,a);
  for(int i=0;i<6;i++)
  {
    vis[craig(shuffle1[i])]=1;
    d[craig(shuffle1[i])]=0;
  }
  q.push(a);
  hecc b;
  while(!q.empty())
  {
    a = q.front();
    q.pop();
    for(int i=0;i<4;i++)
    {
      b.a.x = rectify(dir4[0][i] + a.a.x);
      b.b.x = rectify(dir4[0][i] + a.b.x);
      b.c.x = rectify(dir4[0][i] + a.c.x);

      b.a.y = rectify(dir4[1][i] + a.a.y);
      b.b.y = rectify(dir4[1][i] + a.b.y);
      b.c.y = rectify(dir4[1][i] + a.c.y);

      if(g[b.a.x][b.a.y]=='#')
      {
        b.a.x=a.a.x;
        b.a.y=a.a.y;
      }
      if(g[b.b.x][b.b.y]=='#')
      {
        b.b.x=a.b.x;
        b.b.y=a.b.y;
      }
      if(g[b.c.x][b.c.y]=='#')
      {
        b.c.x=a.c.x;
        b.c.y=a.c.y;
      }
      //if b.a is in a and it is in a fockn taken spot
      if(fall(b.a,a.a))//a was unmoved
      {
        if(fall(b.b,a.b))
        {
          //a and b did not move but c did, so check if c landed on a or b
          if(b.c.x != a.c.x || b.c.y==a.c.y)
          {
            if(fall(b.c,b.b) )
            {
              b.c.x=a.c.x;
              b.c.y=a.c.y;
            }
            else if(fall(b.c,b.a))
            {
              b.c.x=a.c.x;
              b.c.y=a.c.y;
            }
          }
        }
        else if(fall(b.c,a.c))
        {
          //a and c were unmoved but b did, so check if b landed in a or c
          if(fall(b.b,b.c) )
          {
            b.b.x=a.b.x;
            b.b.y=a.b.y;
          }
          else if(fall(b.b,b.a) )
          {
            b.b.x=a.b.x;
            b.b.y=a.b.y;
          }
        }
        else
        {
          //a was unmoved see if b or c landed on a
          if(fall(b.b,b.a) )
          {
            b.b.x=a.b.x;
            b.b.y=a.b.y;
          }
          else if(fall(b.c,b.a))
          {
            b.c.x=a.c.x;
            b.c.y=a.c.y;
          }
        }
      }
      else if(fall(b.b,a.b))
      {
        if(fall(b.c,a.c))
        {
          //b and c unmoved
          if(fall(b.b,b.a) )
          {
            b.a.x=a.a.x;
            b.a.y=a.a.y;
          }
          else if(fall(b.c,b.a))
          {
            b.a.x=a.a.x;
            b.a.y=a.a.y;
          }
        }
        else
        {
          //only b
          if(fall(b.b,b.a) )
          {
            b.a.x=a.a.x;
            b.a.y=a.a.y;
          }
          else if(fall(b.b,b.c) )
          {
            b.c.x=a.c.x;
            b.c.y=a.c.y;
          }
        }
      }
      else if(fall(b.c,a.c))
      {
        // just c unmoved
        if(fall(b.b,b.c))
        {
          b.b.x=a.b.x;
          b.b.y=a.b.y;
        }
        else if(fall(b.c,b.a) )
        {
          b.a.x=a.a.x;
          b.a.y=a.a.y;
        }
      }
      if(vis[craig(b)]!=1)
      {
        shuff(shuffle1,b);
        //if any of b.a, b.b,b.c occupies it.
        //identify, by whom it was occupied ;_;
        for(int j=0;j<6;j++)
        {
          vis[craig(shuffle1[j])]=1;
          d[craig(shuffle1[j])]=1+d[craig(a)];
        }
        q.push(b);
      }
    }
  }
  a.a.x= dest[0].x, a.a.y = dest[0].y;
  a.b.x = dest[1].x, a.b.y = dest[1].y;
  a.c.x = dest[2].x, a.c.y = dest[2].y;
  if(vis[craig(a)]==0)printf("Case %d: trapped\n",test);
  else printf("Case %d: %d\n",test,d[craig(a)]);

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
