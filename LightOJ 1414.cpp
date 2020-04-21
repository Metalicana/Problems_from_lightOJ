#include <bits/stdc++.h>
using namespace std;
int convert(char c[])
{
    int x = strlen(c);
    if(c[0] == 'J' && x == 7)return 1;
    if(c[0] == 'F')return 2;
    if(c[0] == 'M' && x == 5)return 3;
    if(c[0] == 'A' && x == 4)return 4;
    if(c[0] == 'M')return 5;
    if(c[0] == 'J' && c[3] == 'e')return 6;
    if(c[0] == 'J')return 7;
    if(c[0] == 'A')return 8;
    if(c[0] == 'S')return 9;
    if(c[0] == 'O')return 10;
    if(c[0] == 'N')return 11;
    return 12;
}
int main()
{
   // freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int test=1; test<=t; test++)
    {
        char g1[15],g2[15];
        int d1,y1,m1,x;
        int d2,y2,m2;
        int ys,ye;
        int lc =0;
        scanf("%s %d, %d",g1,&d1,&y1);
        scanf("%s %d, %d",g2,&d2,&y2);
        m1 = convert(g1);
        m2 = convert(g2);
        if(m1 > 2)y1++;
        if(m2 == 1 || (m2 == 2 && d2 < 29))y2--;
        int ans = y2/4 - (y1-1)/4;
        ans -= y2/100 - (y1-1)/100;
        ans += y2/400 - (y1-1)/400;
        printf("Case %d: %d\n",test,ans);
    }
    return 0;
}
