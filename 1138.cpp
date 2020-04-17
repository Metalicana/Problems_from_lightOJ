#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long k[20];
    long long j[20];
    long long power = 5;
    long long summer = 1;
    for(int w=0; w<15; w++)
    {
        k[w]=summer;
        j[w]=power;
        summer = summer + power;
        power = power*5;
    }
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        int x;
        scanf("%d",&x);

            long long sum = 0,s;
            for(int w=14; w>=0; w--)
            {
                if(x >= k[w])
                {
                    s = 0;
                    while(x >= k[w])
                    {
                        x -= k[w];
                        sum += j[w];
                        s++;
                        if(s > 4)
                        {
                            break;
                        }
                    }
                    if(s > 4)break;
                }
            }
            if(s > 4)printf("Case %d: impossible\n",test);
            else printf("Case %d: %lld\n",test,sum);

    }
    return 0;
}
