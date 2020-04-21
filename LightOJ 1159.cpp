#include <bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100];
int lcs[100][100][100];
int main()
{

    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%s%s%s",a,b,c);
    int la = strlen(a);
    int lb = strlen(b);
    int lc = strlen(c);
    for(int i=0;i<=la;i++)
    {
        for(int j=0;j<=lb;j++)
        {
            for(int k=0;k<=lc;k++)
            {
                if(i == 0 || j ==0 || k == 0)
                {
                    lcs[i][j][k] = 0;
                }
                else if(a[i-1] == b[j-1] && b[j-1] ==c[k-1])
                {
                    lcs[i][j][k] = 1 + lcs[i-1][j-1][k-1];
                }
                else
                {
                    lcs[i][j][k] = max(lcs[i-1][j][k],max(lcs[i][j-1][k],lcs[i][j][k-1]));
                }
            }
        }
    }
    printf("Case %d: %d\n",test,lcs[la][lb][lc]);
    }
    return 0;
}
