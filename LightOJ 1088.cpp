#include <bits/stdc++.h>
using namespace std;
int ara[100006];
int n,q,t,a,b,leftt,rightt,mid,ans,bans;
int main()
{
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%d%d",&n,&q);
        for(int w=0; w<n; w++)scanf("%d",&ara[w]);
        printf("Case %d:\n",test);
        for(int w=0; w<q; w++)
        {
            scanf("%d%d",&a,&b);
            leftt = 0;
            rightt = n-1;
            if(a > ara[rightt])
            {
                ans = 0;
                bans = -1;
                goto korbo;
            }
            if(a <= ara[leftt])
            {
                ans = leftt;
                goto hagu;
            }
            if(b < ara[leftt])
            {
                ans = 0;
                bans = -1;
                goto korbo;
            }

            while(leftt < rightt)
            {
                if(leftt+1 == rightt)
                {
                    if(ara[leftt]>=a)
                    {
                        ans = leftt;
                        break;
                    }
                    else
                    {
                        ans = rightt;
                        break;
                    }
                }
                mid = (leftt+rightt)/2;
                if(ara[mid]==a)
                {
                    ans = mid;
                    break;
                }
                else if(ara[mid]>a)
                {
                    rightt = mid;
                }
                else leftt = mid;
            }
hagu:

            leftt = 0;
            rightt = n-1;
            if(b > ara[rightt])
            {
                bans = rightt;
                goto korbo;
            }
            while(leftt < rightt)
            {
                if(leftt+1 == rightt)
                {
                    if(ara[rightt]<=b)
                    {
                        bans = rightt;
                        break;
                    }
                    else
                    {
                        bans = leftt;
                        break;
                    }
                }
                mid = (leftt+rightt)/2;
                if(ara[mid]==b)
                {
                    bans = mid;
                    break;
                }
                else if(ara[mid]>b)
                {
                    rightt = mid;
                }
                else leftt = mid;
            }
korbo:
            printf("%d\n",bans-ans+1);

        }
    }
    return 0;
}
