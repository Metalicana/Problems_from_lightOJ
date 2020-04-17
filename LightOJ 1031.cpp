#include <bits/stdc++.h>
using namespace std;
#define inf 1000000
int n,q,k;
int ara[105];
int memo[105][105];
int dp(int i,int j)
{
    if(i>j) return 0;
    if(i == j)return ara[i];
    if(memo[i][j]!=-1)return memo[i][j];
    int ans=-inf;
    int sum = 0;
    for(int w=i;w<=j;w++)
    {
        sum += ara[w];
        ans = max(ans,sum-dp(w+1,j));
    }
    sum = 0;
    for(int w=j;w>=i;w--)
    {
        sum += ara[w];
        ans = max(ans,sum-dp(i,w-1));
    }

    memo[i][j]=ans;
    return memo[i][j];


}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        memset(memo,-1,sizeof memo);
        for(int w=0;w<n;w++)
        {
            scanf("%d",&ara[w]);
        }
        q=0;k=0;
        printf("Case %d: %d\n",test,dp(0,n-1));


    }
    return 0;
}
