
#include <bits/stdc++.h>
using namespace std;
int a,b,n,m,mod;
struct matrix
{
    int v[5][5];
    int row,col;
};
matrix mul(matrix a,matrix b)
{
    matrix c;
    c.row = a.row;
    c.col = b.col;
    for(int w=0;w<c.row;w++)
    {
        for(int q=0;q<c.col;q++)
        {
            int sum = 0;
            for(int r=0;r<a.col;r++)
            {
                sum +=  a.v[w][r]*b.v[r][q];
                sum = sum%mod;
            }
            c.v[w][q] = sum;
        }
    }
    return c;
}
matrix exp(matrix a,int n)
{
    if(n == 1)return a;
    if(n%2==1)return mul(a,exp(a,n-1));
    matrix ret = exp(a,n/2);
    ret = mul(ret,ret);
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d%d%d",&a,&b,&n,&m);
        matrix mat;
        mat.row = mat.col = 2;
        mod = 1;
        for(int w=0;w<m;w++)
        {
            mod = mod*10;
        }
        a = a%mod;
        b = b%mod;
        mat.v[0][0]=1;
        mat.v[0][1]=1;
        mat.v[1][0]=1;
        mat.v[1][1]=0;
        if(n < 3)
        {
            if(n == 0)printf("Case %d: %d\n",test,a);
            else if(n==1)printf("Case %d: %d\n",test,b);
            else printf("Case %d: %d\n",test,(a+b)%mod);
        }
        else
        {
            mat = exp(mat,n-1);
            int ans = b*mat.v[0][0] + a*mat.v[0][1];
            ans %= mod;
            printf("Case %d: %d\n",test,ans);
        }



    }
    return 0;
}
