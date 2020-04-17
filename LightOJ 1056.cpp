#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        double a,b;
        scanf("%lf : %lf",&a,&b);
        double k = a*a - b*b;
        k = k / (a*a + b*b);
        k = acos(k);
        double l = sqrt(a*a + b*b);
        l /= (2.0*a);
        l = (1.0 + l*k);
        l = 200.00/l;
        double w = b*l/a;
        printf("Case %d: %.10lf %.10lf\n",test,l,w);
    }
    return 0;
}
