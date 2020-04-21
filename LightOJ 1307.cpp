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
        int ara[n+5];
        for(int w=0;w<n;w++)scanf("%d",&ara[w]);
        sort(ara,ara+n);

        int l,r,m,ans,cntr=0;
        for(int w=0;w<n-1;w++)
        {
            for(int q=w+1;q<n;q++)
            {
                l = q;
                r = n-1;
                m;
                while(l < r)
                {
                    m=(l+r)/2;
                    if(l==r)
                    {
                        ans = l;
                        break;
                    }
                    else if(l+1 == r)
                    {
                        if(ara[w]+ara[q] > ara[r])
                        {
                            ans = r;
                            break;
                        }
                        else
                        {
                            ans = l;
                            break;
                        }
                    }
                    else
                    {
                        if(ara[w]+ara[q] > ara[m])
                        {
                            l = m;
                        }
                        else r = m;
                    }
                }
               // cout <<w << " " << q << " " << ans << endl;
                cntr += max(0,ans-q);

            }
        }
        printf("Case %d: %d\n",test,cntr);
    }
    return 0;
}
