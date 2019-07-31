#include <bits/stdc++.h>
using namespace std;
#define inf 1000000
char c[10005];
int memo[10005];
int t,n,ans;
bool pal(int i,int j)
{
    int q = j;
    for(int w=i;w!=q;w++)
    {
        if(w > q )return 1;
        if(c[w]!=c[q])return 0;
        q--;

    }
    return 1;
}
int dp(int i)
{
    if(memo[i]!=-1)return memo[i];
    if(i >= n)return 0;
    int ans = inf;
    for(int w=n-1;w>=i;w--)
    {
        if(pal(i,w))
        {
            ans = min(ans,1+dp(w+1));
        }
    }
    memo[i] = ans;
    return ans;
}
int main()
{
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {   memset(memo,-1,sizeof memo);
        scanf("%s",c);
        n = strlen(c);
        ans = dp(0);
        printf("Case %d: %d\n",test,ans);
    }
    return 0;
}
