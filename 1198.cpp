#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int n,me[55],he[55],grid[55][55];
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {

        scanf("%d",&n);
        for(int w=0;w<n;w++)scanf("%d",&me[w]);
        for(int w=0;w<n;w++)scanf("%d",&he[w]);
        int marker[55],barker[55];
        memset(marker,0,sizeof marker);
        memset(barker,0,sizeof barker);
        sort(me,me+n);
        sort(he,he+n,cmp);
        int ans = 0;
        int odd =0 ;
        for(int w=0;w<n;w++)
        {
            int q = 0;
            int s = 0;
            while(q < n )
            {
                if(he[q] < me[w])
                {
                    if(!marker[q])
                    {
                        marker[q] = 1;
                        s=2;
                        if(he[q] == me[w])s=1;
                        break;
                    }
                }
                q++;
            }
            ans += s;
            if(s)barker[w]=1;
        }
        for(int w=0;w<n;w++)
        {
            if(!barker[w])
            {
                for(int q=0;q<n;q++)
                {
                    if(!marker[q] && me[w] == he[q])
                    {
                        ans++;
                        marker[q]=1;
                        barker[w]=1;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n",test,ans);

    }

    return 0;
}
