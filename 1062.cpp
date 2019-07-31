#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        double x,y,c,d,hx,hy,m,te;
        scanf("%lf%lf%lf",&x,&y,&c);
        double base,e,b;
        e = min(x,y);
        b = 0.0;
        while(true)
        {
            base = (b+e)/2.00;
            hx = sqrt(x*x - base*base);
            hy = sqrt(y*y - base*base);
            te = hx*hy*1.0/(hx+hy)*1.0;
            if(abs(te-c)<=0.000000001)break;
            else
            {
                if(te > c)
                {
                    b = base;
                }
                else e = base;
            }
        }
        printf("Case %d: %.10lf\n",test,base);
    }
    return 0;
}
