#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
struct node
{
    int zero,one,two;
}tree[3*maxn];
int lazy[3*maxn];
int ripple(int *a,int *b,int *c)
{
    int tempa,tempb,tempc;
    tempa = *a;
    tempb = *b;
    tempc = *c;
    *a = tempc;
    *b =tempa;
    *c = tempb;
}
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].zero = 1;
        tree[node].one = 0;
        tree[node].two = 0;
        return;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = 0;
    tree[node].two = 0;
}
void update(int node,int b,int e,int i,int j)
{

    if(lazy[node] != 0)
    {
        lazy[node]%=3;

        for(int w=0;w<lazy[node];w++)
        {
            ripple(&tree[node].zero,&tree[node].one,&tree[node].two);

        }
        if(b != e)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;

    }
    if(b> j || e < i)return;
    if(b >= i && e <= j)
    {
        ripple(&tree[node].zero,&tree[node].one,&tree[node].two);
        if(b != e)
        {
            lazy[node*2] += 1;
            lazy[node*2 + 1] += 1;
        }
        return;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].zero = tree[left].zero + tree[right].zero;
    tree[node].one = tree[left].one + tree[right].one;
    tree[node].two = tree[left].two + tree[right].two;
}
int query(int node,int b,int e,int i,int j)
{

    if(lazy[node] != 0)
    {
        lazy[node]%=3;
        for(int w=0;w<lazy[node];w++)
        {
            ripple(&tree[node].zero,&tree[node].one,&tree[node].two);

        }
        if(b != e)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;

    }
    if(b> j || e < i)return 0;
    if(b >= i && e <= j)
    {
        return tree[node].zero;
    }
    int p1,p2;
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;

    p1 = query(left,b,mid,i,j);
    p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}
int main()
{
    //freopen("o.txt","w",stdout);
    int t,n,q,i,a,b;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d%d",&n,&q);
        memset(lazy,0,sizeof lazy);
        init(1,0,n-1);
        printf("Case %d:\n",test);
        while(q--)
        {
            scanf("%d%d%d",&i,&a,&b);
            if(i== 0)
            {
                update(1,0,n-1,a,b);
            }
            else
            {
                printf("%d\n",query(1,0,n-1,a,b));
            }
        }
    }
    return 0;
}
