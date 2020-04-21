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
        set < pair<int,int> > x;
        pair <int,int> c;
        int ara[105];
        int old_indx[105];
        for(int w=1;w<=n;w++)
        {
            scanf("%d",&ara[w]);
            old_indx[ara[w]] = w;
        }
        //sort(ara+1,ara+n+1);
        int xx = 0;
        int j;
        for(int w=1;w<=n;w++)
        {
            if(ara[w] != w)
            {
                xx++;
                j = old_indx[w];
                swap(ara[w],ara[old_indx[w]]);
                old_indx[ara[old_indx[w]]]=j;
            }
        }
        printf("Case %d: %d\n",test,xx);
    }
    return 0;
}
