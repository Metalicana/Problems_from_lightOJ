#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        double a,b,c,d,ans;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(c == a)
        {
            ans = c*d;
        }
        else
        {
            double j = d*d - b*b;
            double k = c-a;
            double x = -j-(k*k);
            x /= (2.0*k);
            ans = d*d - x*x;
            ans = sqrt(ans);
            ans = 0.5 * ans * (a+c);
        }
        printf("Case %d: %.10lf\n",test,ans);
    }
    return 0;
}
