#include <bits/stdc++.h>
using namespace std;
int ara[30009];
pair <int,int> kara[30009];
int n;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        for(int w=0;w<n;w++)
        {
            scanf("%d",&ara[w]);
            kara[w].first=ara[w];
            kara[w].second = w;
        }
        sort(kara,kara+n);
        int maxn = n*kara[0].first;
        int i,j,s,d;
        for(int w=1;w<n;w++)
        {
            i = kara[w].second-1;
            j = kara[w].second+1;
            s=1;d=0;
            while(i >= 0 && ara[i] >= kara[w].first)
            {
                i--;
                s++;
            }
            while(j < n && ara[j] >= kara[w].first)
            {
                j++;
                d++;
            }
            s = s+d;
            if(maxn < s*kara[w].first)maxn = s*kara[w].first;
        }
        printf("Case %d: %d\n",test,maxn);

    }
    return 0;
}
