#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
int n,m,q,r;
vector <int> divi[100006];
bool mark[maxn];
bool isprim[maxn];
int primes[maxn];
void siv()
{
    primes[0]=2;
    isprim[2]=1;
    int d = 1;
    for(int w=3; w<=maxn; w+=2)
    {
        if(!mark[w])
        {
            isprim[w]=1;
            primes[d++]=w;
            for(int q=w*w; q<=maxn; q+= (2*w))mark[q]=1;
        }
    }
}
int nod(int x)
{
    int lim = sqrt(x);
    int j;
    int sum = 1;
    for(int i=0; primes[i]<=lim; i++)
    {
        if(x%primes[i]==0)
        {
            j = 0;
            while(x%primes[i]==0)
            {
                x /= primes[i];
                j++;
            }
            sum *= (j+1);
        }
        lim = sqrt(x);
    }
    if(x != 1)sum *=2;
    return sum;
}
double dp[100005];
double khela(int x)
{
    if(dp[x]!=-1.00)return dp[x];
    int w = nod(x);
    double sum = (double)w;
    for(int i=0; i<divi[x].size(); i++)
    {
        if(divi[x][i]!=x)
        {
            sum += khela(divi[x][i]);
        }


    }
    dp[x] = (double)sum*1.00;
    dp[x]/=(((double)w-1.00)*1.00);
    return dp[x];
}
int main()
{
    siv();
    for(int w=0;w<=100002;w++)dp[w]=-1.00;
    for(int w=2; w<=100005; w++)
    {
        for(int q=w; q<=100005; q += w)
        {
            divi[q].push_back(w);
        }
    }
    int t;
    double ans;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%d",&n);
        if(n == 1)ans=0.00;
        else ans =khela(n);
        printf("Case %d: %.10lf\n",test,ans);
    }
    return 0;
}
