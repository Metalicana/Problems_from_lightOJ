#include <bits/stdc++.h>
using namespace std;
string g;
int memo[105][105];
int dp(int i,int j)
{
    if(i>j)return 0;
    if(i==j)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    if(i+1 == j)
    {
        if(g[i]==g[j])return 0;
        return 1;
    }
    if(g[i]==g[j])
    {
        memo[i][j] = dp(i+1,j-1);
        return memo[i][j];
    }
    else
    {
        memo[i][j] = min(1+dp(i+1,j),1+dp(i,j-1));
        return memo[i][j];
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        memset(memo,-1,sizeof memo);
        cin >> g;
        printf("Case %d: %d\n",test,dp(0,g.size()-1));
    }
    return 0;
}
