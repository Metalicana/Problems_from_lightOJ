#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        int n;
        int sum = 0;
        scanf("%d",&n);
        int x,y;
        for(int w=0; w<n; w++)
        {
            scanf("%d",&x);

            if(w==0)y=x;
            else y = (y^x);
            sum += x;
        }
        if(sum == n)
        {
            if(n%2 == 0)printf("Case %d: Alice\n",test);
            else printf("Case %d: Bob\n",test);
        }
        else
        {
            if(y !=0 )
            {
                if(n == 1 && y == 1)printf("Case %d: Bob\n",test);
                else printf("Case %d: Alice\n",test);
                //else printf("Case %d: Bob\n",test);
            }
            else
            {
                printf("Case %d: Bob\n",test);
            }
        }
    }
    return 0;
}
