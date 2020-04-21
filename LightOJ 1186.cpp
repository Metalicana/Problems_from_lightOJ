#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        vector <int>a,b;
        int x;
        for(int w=0;w<n;w++)
        {
            scanf("%d",&x);
            a.push_back(x);
        }
        for(int w=0;w<n;w++)
        {
            scanf("%d",&x);
            b.push_back(x);
        }
        int s;
        for(int w=0;w<n;w++)
        {
            if(w == 0)s = (b[0]-a[0]-1);
            else s = (s ^ (b[w]-a[w]-1));
        }
        if(s==0)printf("Case %d: black wins\n",test);
        else printf("Case %d: white wins\n",test);

    }
    return 0;
}
