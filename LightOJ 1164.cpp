#include <bits/stdc++.h>
using namespace std;
#define maxn 100009
long long ara[maxn];
long long n,q,r,s,x,y,v;
struct node
{
    long long val,prop;
}tree[3*maxn];
void init(long long node,long long b,long long e)
{
    if(b == e)
    {
        tree[node].val = 0;
        tree[node].prop = 0;
        return;
    }
    long long left  = 2*node;
    long long right = left+1;
    long long mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[left].val = tree[right].val = 0;
    tree[left].prop = tree[right].prop = 0;
    tree[node].val = tree[node].prop = 0;
}
void update(long long node,long long b,long long e,long long i,long long j,long long x)
{
    if(b > j || e < i)return;
    if(b >= i && e <= j)
    {
        tree[node].prop += x;
        tree[node].val += (e-b+1)*x;
        return;
    }
    long long left = 2*node;
    long long right = left+1;
    long long mid = (b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].val = tree[left].val + tree[right].val + (e-b+1)*tree[node].prop;

}
long long query(long long node,long long b,long long e,long long i,long long j,long long carry=0)
{
    if(b > j || e < i )return 0;
    if(b >= i && e <= j)
    {
        return tree[node].val + carry*(e-b+1);
    }
    long long left = 2*node;
    long long right = left+1;
    long long mid = (b+e)/2;
    long long p1,p2;
    p1 = query(left,b,mid,i,j,carry+tree[node].prop);
    p2 = query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    //freopen("o.txt","w",stdout);
    long long t;
    scanf("%lld",&t);
    for(long long test=1;test<=t;test++)
    {
        printf("Case %lld:\n",test);
        scanf("%lld%lld",&n,&q);
        init(1,1,n);
        while(q--)
        {
            scanf("%lld",&r);
            if(r == 0)
            {
                scanf("%lld%lld%lld",&x,&y,&v);
                update(1,1,n,x+1,y+1,v);
            }
            else
            {
                scanf("%lld%lld",&x,&y);
                printf("%lld\n",query(1,1,n,x+1,y+1));
            }
        }

    }
    return 0;
}
