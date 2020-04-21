#include <bits/stdc++.h>
using namespace std;
double sex[1000005];
int main()
{
    //freopen("o.txt","w",stdout);
    double ex = 1.0;
    for(int w=2;w<=100000000;w++)
    {
        ex = (ex*(double)w + 1.0)/(double)w;
        if(w % 100 == 0)sex[w/100] = ex;

    }
    int t;
    scanf("%d",&t);
    sex[0]=0.0;
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        int l,k;
        l = n/100;
        double ss = sex[l];
        l*=100;
        //l++;
        k = n%100;

        l++;
        //cout << l << " " << k << endl;
        for(int w=l;w < l+k;w++)
        {
            if(w==0)continue;
            ss = (ss*(double)w + 1)/(double)w;
        }
        printf("Case %d: %.12lf\n",test,ss);
    }
}
