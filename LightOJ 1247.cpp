#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int m,n,x,y,z;
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&n,&m);
        for(int w=0;w<n;w++)
        {
            for(int q=0;q<m;q++)
            {
                scanf("%d",&x);
                if(q == 0)z=x;
                else z = z+x;
            }
            if(w == 0)y=z;
            else y = (y ^ z);


        }
        if(y)printf("Case %d: Alice\n",test);
        else printf("Case %d: Bob\n",test);
    }
    return 0;
}
