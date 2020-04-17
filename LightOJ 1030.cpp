#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000
long long n,m,q,t;
double s;
double ara[105];
double mem[105];
double sum;
int main()
{
    scanf("%lld",&t);
    for(long long test=1; test<=t; test++)
    {
        scanf("%lld",&n);
        memset(mem,0.0,sizeof mem);
        for(long long w=1; w<=n; w++)
        {
            //scanf("%lf",&ara[w]);
            if(w == 1)mem[w]=1;

            for(int q=1; q<=6; q++)
            {
                if(q+w <= n)
                {
                    mem[q+w] += (mem[w]/min(6.0,(double)n-w));

                }
            }
            cout << 1.0/mem[w] << endl;

        }
        double ans = 0.0;
        for(int w=1; w<=n; w++)
        {
            ans += (mem[w]*ara[w]);
        }
        printf("Case %lld: %.10lf\n",test,ans);

    }
    return 0;
}
