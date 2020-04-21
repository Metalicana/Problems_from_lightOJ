#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,q;
int type,a,b,x;
int tree[maxn*4];
int prop[maxn*4];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node] = 0;
        prop[node] = -1;
        return;
    }
    int mid = (b+e)/2;
    int left = 2*node;
    int right = left+1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = 0;
    prop[node] = -1;
}
void update(int node,int b,int e,int i,int j,int v)
{
    if(prop[node]!=-1)
    {
        tree[node] = (e-b+1)*prop[node];
        if(b != e)
        {
            prop[2*node] = prop[node];
            prop[2*node + 1] = prop[node];
        }
        prop[node] = -1;

    }
    if(b>j || e < i)return;
    if(b >= i && e <= j)
    {
        tree[node] = (e-b+1)*v;
        if(b != e)
        {
            prop[2*node] = v;
            prop[2*node + 1] = v;
        }
        return;
    }
    int mid = (b+e)/2;
    int left = 2*node;
    int right = left+1;
    update(left,b,mid,i,j,v);
    update(right,mid+1,e,i,j,v);
    tree[node] = tree[left] + tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(prop[node]!=-1)
    {
        tree[node] = (e-b+1)*prop[node];
        if(b != e)
        {
            prop[2*node] = prop[node];
            prop[2*node + 1] = prop[node];
        }
        prop[node] = -1;

    }
    if(b>j || e < i)return 0;
    if(b >= i && e <= j)
    {
        return tree[node];
    }
    int p1,p2,left=2*node,right=2*node+1,mid=(b+e)/2;
    p1 = query(left,b,mid,i,j);
    p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        printf("Case %d:\n",test);
        scanf("%d%d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(prop,0-1,sizeof prop);
        //init(1,0,n-1);
        while(q--)
        {
            scanf("%d%d%d",&type,&a,&b);
            if(type == 1)
            {
                scanf("%d",&x);
                update(1,0,n-1,a,b,x);
            }
            else
            {
                int ans = query(1,0,n-1,a,b);
                int g = __gcd(ans,b-a+1);
                x = b-a+1;
                x /= g;
                ans /= g;
                printf("%d",ans);
                if(x!=1)printf("/%d",x);
                printf("\n");


            }
        }
    }
    return 0;
}
