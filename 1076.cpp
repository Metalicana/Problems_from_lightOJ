#include <bits/stdc++.h>
using namespace std;
#define maxn 1009
#define inf 1000000008
int n,k,a,b,c;
int ara[maxn];
int sum[maxn];
int summit(int i, int j, int sum[])
{
    if(i == j)return ara[i];
    if(i == 0)return sum[j];
    return sum[j]-sum[i-1];
}
bool kraig(int x,int ara[])
{
    int temp_sum = 0,part=0;
    for(int w=0;w<n;w++)
    {
        if(ara[w] + temp_sum > x)
        {
            part++;
            temp_sum = ara[w];
        }
        else temp_sum += ara[w];
    }
    part++;
    if(part > k)return 0;
    else return 1;
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t,ans,left,right,mid;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&n,&k);
        int maxii = 0;
        for(int w=0;w<n;w++)
        {
            scanf("%d",&ara[w]);
            if(ara[w]>maxii)maxii = ara[w];
            if(w == 0)sum[w]=ara[w];
            else sum[w]=ara[w]+sum[w-1];

        }

        if( k > n)ans = maxii;
        else if( k==1)ans=summit(0,n-1,sum);
        else
        {
            left = maxii;
            right = summit(0,n-1,sum);
            while(left < right)
            {
                if(left + 1 == right)
                {
                    if(kraig(left,ara) == 1)
                    {
                        ans = left;
                        break;
                    }
                    else
                    {
                        ans = right;
                        break;
                    }
                }
                mid = (left+right)/2;;
                bool j = kraig(mid,ara);
                if(j)right = mid;
                else left = mid;
            }
        }
        printf("Case %d: %d\n",test,ans);

    }
    return 0;
}
