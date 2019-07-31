#include <bits/stdc++.h>
using namespace std;
int nomc(int x,int k)
{
    int j = 0;
    int p = k;
    while(x/p != 0)
    {
        j += (x/p);
        p = p*k;
    }
    return j;
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n,r,p,q;
        scanf("%d%d%d%d",&n,&r,&p,&q);
        int five = nomc(n,5);
        five -= nomc(n-r,5);
        five -= nomc(r,5);
        int two = nomc(n,2);
        two -= nomc(n-r,2);
        two -= nomc(r,2);

        int kek=0;
        while(p%5 == 0)
        {
            kek++;
            p /=5;
        }
        kek = kek*q;
        five += kek;
        kek = 0;
        while(p%2 == 0)
        {
            kek++;
            p /=2;
        }
        kek *= q;
        two += kek;
        int ans = min(five,two);
        printf("Case %d: %d\n",test,ans);

    }
    return 0;
}
