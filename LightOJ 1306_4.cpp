#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll egcd(ll a,ll b,ll &x,ll &y)
{
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x6,y6,d;
    d = egcd(b%a,a,x6,y6);
    x = y6 - (b/a)*x6;
    y = x6;
    return d;
}
int main()
{
    //freopen("output.txt","w",stdout);
    ll t,a,b,c,x1,x2,y1,y2,ans,x3,x4,z,x,y,z2,bans,y3,y4,x_inter,y_inter,l,m;
    scanf("%lld",&t);
    for(ll test=1; test<=t; test++)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y1,&y2);
        if(a == 0 && b == 0)
        {
            if( c==0)printf("Case %lld: %lld\n",test,(x2-x1+1)*(y2-y1+1));
            else printf("Case %lld: %d\n",test,0);

        }
        else if(a == 0)
        {
            if( c%b == 0)
            {
                l = -c/b;
                if( l >= y1 && l <= y2)printf("Case %lld: %lld\n",test,x2-x1+1);
                else printf("Case %lld: %d\n",test,0);
            }
            else printf("Case %lld: %d\n",test,0);
        }
        else if( b== 0)
        {
            if( c%a == 0)
            {
                l = -c/a;
                if( l >= x1 && l <= x2)printf("Case %lld: %lld\n",test,y2-y1+1);
                else printf("Case %lld: %d\n",test,0);
            }
            else printf("Case %lld: %d\n",test,0);
        }
        else
        {
            z = egcd(a,b,x,y);
            if(c%z != 0)printf("Case %lld: %d\n",test,0);
            else
            {
                x = x* (-c/z);
                y = y*(-c/z);
                x_inter = b/z;
                y_inter = a/z;
                x1 = x1 + ((x-x1)%abs(x_inter) + abs(x_inter))%abs(x_inter);
                x2 = x2 + ((x-x2)%abs(x_inter) - abs(x_inter))%abs(x_inter);
                if(x1>x2)
                {
                    printf("Case %lld: %d\n",test,0);
                    continue;
                }
                y3 = y + (-y_inter)*((x1-x)/x_inter);
                y4 = y + (-y_inter)*((x2-x)/x_inter);
                if(y3>y4) swap(y3,y4);
                y1 = max(y3,y1);
                y2 = min(y4,y2);
                y1 = y1 + ((y-y1)%abs(y_inter) + abs(y_inter))%abs(y_inter);
                y2 = y2 + ((y-y2)%abs(y_inter) - abs(y_inter))%abs(y_inter);
                if(y1>y2)printf("Case %lld: %d\n",test,0);
                else
                {
                    ans = (y2-y1)/abs(y_inter) +1;
                    printf("Case %lld: %lld\n",test,ans);
                }
            }
        }
    }

    return 0;
}

