#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
int main()
{
    //freopen("o.txt","w",stdout);
    int t,n,k,a;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&n,&k);
        vector <int> result(10010);
        vector <int> coins;
        result[0]=1;
        for(int w=0;w<n;w++)
        {
            scanf("%d",&a);
            coins.push_back(a);
        }
        for(int w=0;w<coins.size();w++)
        {
            for(int q=coins[w];q<=k;q++)
            {
                result[q] = (result[q]%mod + result[q-coins[w]]%mod)%mod;
            }
        }
        printf("Case %d: %d\n",test,result[k]);

    }
    return 0;
}
