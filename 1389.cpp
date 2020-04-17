#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
int memo[105];
int call(int i)
{
    if(i >= n)return 0;
    if(memo[i]!=-1)return memo[i];
    if(s[i]=='#')return memo[i] = call(i+1);
    else
    {
        int x = 1 + call(i+2);
        int y = 1 + call(i+3);
        return memo[i] = min(x,y);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        memset(memo,-1,sizeof memo);
        scanf("%d%s",&n,s);
        printf("Case %d: %d\n",test,call(0));

    }
    return 0;
}
