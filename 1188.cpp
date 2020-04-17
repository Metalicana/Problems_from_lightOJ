#include <bits/stdc++.h>
using namespace std;
struct query
{
  int L,R,idx;
}qq[100006];
int block;
bool cmp(query a, query b)
{
  if(a.L/block != b.L/block)return a.L/block < b.L/block;
  else  return a.R < b.R;

}
int ara[100006];
int ans[100006];
int freq[100006];
int n,q;
int main()
{
  //freopen("o.txt","w",stdout);
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    scanf("%d%d",&n,&q);
    memset(freq,0,sizeof freq);
    for(int w=0;w<n;w++)
    {
      scanf("%d",&ara[w]);
    }
    for(int w=0;w<q;w++)
    {
      scanf("%d%d",&qq[w].L,&qq[w].R);
      if(qq[w].L > qq[w].R)swap(qq[w].L,qq[w].R);
      qq[w].L--;
      qq[w].R--;
      qq[w].idx = w;
    }
    block = (int)sqrt(n);
    sort(qq,qq+q,cmp);
    int curL = 0, curR = 0, L = 0, R = 0,s=0;
    curL = qq[0].L;
    curR = qq[0].R;
    for(int w=curL;w<=curR;w++)
    {
      if(freq[ara[w]]==0)s++;
      freq[ara[w]]++;
    }
    ans[qq[0].idx] = s;
    for(int w=1;w<q;w++)
    {
      L = qq[w].L,R=qq[w].R;
      while(curL > L)
      {
        curL--;
        if(freq[ara[curL]]==0)s++;
        freq[ara[curL]]++;

      }
      while(curR < R)
      {
        curR++;
        if(freq[ara[curR]]==0)s++;
        freq[ara[curR]]++;

      }
      while(curL < L)
      {
        if(freq[ara[curL]]==1)s--;
        if(freq[ara[curL]]!=0)freq[ara[curL]]--;
        curL++;
      }
      while(curR > R)
      {
        if(freq[ara[curR]]==1)s--;
        if(freq[ara[curR]]!=0)freq[ara[curR]]--;
        curR--;
      }
      ans[qq[w].idx] = s;
    }
    printf("Case %d:\n",test);
    for(int w=0;w<q;w++)
    {
      printf("%d\n",ans[w]);
    }

  }
}
