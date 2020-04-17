#include <bits/stdc++.h>
using namespace std;
int m,n;
int digits[15];
int deepee[15][15][15];
int dp(int i,int sz,int prev)
{
    if(deepee[i][sz][prev]!=-1)return deepee[i][sz][prev];
    if(sz == n)return 1;
    if(i >= m)return 0;
    int pizza = 0;
    for(int w=0;w<m;w++)
    {
        if(abs(digits[w] - prev) <= 2 || prev == 10)
        {
            pizza += dp(w,sz+1,digits[w]);
        }
    }
    deepee[i][sz][prev] = pizza;
    return deepee[i][sz][prev];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&m,&n);
        for(int w=0;w<m;w++)scanf("%d",&digits[w]);
        memset(deepee,-1,sizeof deepee);
        int ans = 0;
        ans = dp(0,0,10);
        printf("Case %d: %d\n",test,ans);
    }
    return 0;
}
