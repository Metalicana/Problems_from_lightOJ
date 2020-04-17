#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define mod 1000000007
int a,b,c,d,e,n;
int ara[maxn],kara[maxn];
int tree[4*maxn];
map <int, int> ass,bass;
void update(int node,int b,int e, int i, int x)
{
    if(i < b || i > e)return;
    if(b>= i && e <= i)
    {
        tree[node]=x;
        return;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    tree[node] = (tree[left]%mod+tree[right]%mod)%mod;
}
int query(int node,int b,int e,int i,int j)
{
    if(i > e || j < b)return 0;
    if(b >= i && e <= j)
    {
        return tree[node];
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return (p1%mod+p2%mod)%mod;

}
int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        memset(tree,0,sizeof tree);
        ass.clear();
        for(int w=0;w<n;w++)
        {
            scanf("%d",&ara[w]);
            kara[w]=ara[w];
        }
        sort(ara,ara+n);
        int q = 1;
        for(int w=0;w<n;w++)
        {
            if(ass[ara[w]] == 0)
            {
                ass[ara[w]] = q;
                bass[q++]=ara[w];
            }
        }
        int bullshit[maxn];
        int summ = 0;
        memset(bullshit,0,sizeof bullshit);
        int sum[maxn];
        memset(sum,0,sizeof sum);
        q--;
        for(int w=0;w<n;w++)
        {
            update(1,1,q,ass[kara[w]],1+query(1,1,q,1,ass[kara[w]]));
            sum[ass[kara[w]]] = query(1,1,q,ass[kara[w]],ass[kara[w]]);
        }
        for(int w=1;w<=q;w++)
        {
            summ = (summ+sum[w])%mod;
        }
        printf("Case %d: %d\n",test,summ);



    }
    return 0;
}
