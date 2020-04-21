#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        n*=2;
        int ara[n];
        for(int w=0;w<n;w++)
        {
            scanf("%d",&ara[w]);
        }
        int s = ara[1]-ara[0]-1;
        for(int w=3;w<n;w+=2)
        {
            s = (s ^ (ara[w]-ara[w-1]-1));
        }
        if(!s)printf("Case %d: Bob\n",test);
        else printf("Case %d: Alice\n",test);

    }
    return 0;
}
