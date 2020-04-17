#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,y,z;
    int x1[105],x2[105],y1[105],y2[105],z1[105],z2[105];
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%d",&n);
        for(int w=0; w<n; w++)
        {
            scanf("%d%d%d%d%d%d",&x1[w],&y1[w],&z1[w],&x2[w],&y2[w],&z2[w]);
        }
        sort(x1,x1+n);
        sort(x2,x2+n);
        sort(y1,y1+n);
        sort(y2,y2+n);
        sort(z1,z1+n);
        sort(z2,z2+n);
        //cout << x1[n-1] << " " << x2[0] << " " << y1[n-1] << " " << y2[0] << z1[n-1] << " " << z2[0] << endl;
        x = -x1[n-1]+x2[0];
        if(x < 0)
        {
            printf("Case %d: 0\n",test);
        }
        else
        {
            y = -y1[n-1]+y2[0];
            if(y < 0)
            {
                printf("Case %d: 0\n",test);
            }
            else
            {
                z = -z1[n-1]+z2[0];
                if(z < 0)
                {
                    printf("Case %d: 0\n",test);
                }
                else printf("Case %d: %d\n",test,x*y*z);
            }
        }
    }
}
