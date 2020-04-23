#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define maxn 100000
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int mod(int x,int y)
{
  int s;
  s = abs(x)/y;
  if(x<0)s--;
  return x-y*s;
}
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;
int xi,yi,xf,yf;
int levelF[205][205],levelJ[205][205];
bool visF[205][205],visJ[205][205];
char g[205][205];
vector< pii> vec;
bool valid(int x,int y)
{
  return x>=0&&x<row&&y>=0&&y<col;
}
void bfsFire(pii u)
{
  queue < pii > q;
  levelF[u.x][u.y] = 0;
  visF[u.x][u.y] = 1;
  q.push(u);
  int ix,iy;
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(int w=0;w<4;w++)
    {
      ix = u.x + dir4[0][w];
      iy = u.y + dir4[1][w];
      if(valid(ix,iy) && (g[ix][iy]=='.' ||g[ix][iy]=='J') )
      {
        if(visF[ix][iy] == 0 || levelF[ix][iy] > levelF[u.x][u.y] + 1)
        {
          visF[u.x + dir4[0][w]][u.y + dir4[1][w]] = 1;
          levelF[u.x + dir4[0][w]][u.y + dir4[1][w]] = levelF[u.x][u.y]+1;
          q.push(mp(u.x + dir4[0][w],u.y + dir4[1][w]));
        }

      }
    }
  }

}
void bfsJ(pii u)
{
  queue < pii > q;
  levelJ[u.x][u.y] = 0;
  visJ[u.x][u.y] = 1;
  q.push(u);
  while(!q.empty())
  {
    u = q.front();
    q.pop();
    for(int w=0;w<4;w++)
    {
      if(valid(u.x + dir4[0][w],u.y + dir4[1][w]) && g[u.x + dir4[0][w]][u.y + dir4[1][w]]=='.')
      {
        if(levelF[u.x + dir4[0][w]][u.y + dir4[1][w]]  > levelJ[u.x][u.y]+1  )
        {
          if(visJ[u.x + dir4[0][w]][u.y + dir4[1][w]] == 0)
          {
            visJ[u.x + dir4[0][w]][u.y + dir4[1][w]] = 1;
            levelJ[u.x + dir4[0][w]][u.y + dir4[1][w]] = levelJ[u.x][u.y]+1;
            q.push(mp(u.x + dir4[0][w],u.y + dir4[1][w]));
          }
        }
      }
    }
  }
}
void solve(int test)
{
  scanf("%d%d",&row,&col);
  for(int w=0;w<row;w++)
  {
    scanf("%s",g[w]);
    for(int q=0;q<col;q++)
    {
      if(g[w][q] == 'J')
      {
        xi = w;yi = q;
      }
      else if(g[w][q] == 'F')
      {
        vec.pb(mp(w,q));
      }
    }
  }
  for(int w=0;w<(int)vec.size();w++)
  {
    bfsFire(mp(vec[w].x,vec[w].y));
  }

  bfsJ(mp(xi,yi));
  int ans = 100000000;
  for(int w=0;w<row;w++)
  {
    //cout << levelJ[w][0] <<  " " << levelJ[w][col-1] << endl;
    if(visJ[w][0] == 1)ans = min(ans,levelJ[w][0]);
    if(visJ[w][col-1] == 1)ans = min(ans,levelJ[w][col-1]);
  }
  for(int w=0;w<col;w++)
  {
  //  trace2(levelJ[0][w],levelJ[row-1][w])
    if(visJ[0][w] == 1)ans = min(ans,levelJ[0][w]);
    if(visJ[row-1][w] == 1)ans = min(ans,levelJ[row-1][w]);
  }
  if(ans ==100000000 )printf("Case %d: IMPOSSIBLE\n",test);
  else printf("Case %d: %d\n",test,ans+1);
}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    memset(visF,0,sizeof visF);
    memset(visJ,0,sizeof visJ);
    for(int w=0;w<205;w++)
    {
      for(int q=0;q<205;q++)levelF[w][q]=50000;
    }
    vec.clear();
  //  memset(levelJ,-1,sizeof levelJ);
    solve(test);
  }
}
int main()
{
  freopen("o.txt","w",stdout);
  test();
  return 0;
}
