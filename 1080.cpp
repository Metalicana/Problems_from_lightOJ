#include <bits/stdc++.h>
using namespace std;
#define maxn 100003
int n,m,q,t,a,b,d,l;
char g[maxn];
char c[maxn];
struct node
{
    int prop;
} tree[3*maxn];
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].prop = 0;
        return;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[left].prop = 0 , tree[right].prop = 0;
    tree[node].prop = 0;
}
void update(int node,int b,int e,int i,int j)
{
    if(b > j || e < i)return;
    if(b >= i && e <= j)
    {
        tree[node].prop++;
        return;
    }

    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
int query(int node,int b,int e,int i,int carry=0)
{
    if(b > i || e < i || b>e)return 0;
    if(b >= i && e <= i)
    {
        return carry+tree[node].prop;
    }
    int left = 2*node;
    int right = left+1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,carry+tree[node].prop);
    int p2 = query(right,mid+1,e,i,carry+tree[node].prop);
    return p1+p2;

}
int main()
{
    //freopen("o.txt","w",stdout);
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%s",g);
        scanf("%d",&q);
        d = strlen(g);
        d--;
        init(1,0,d);
        printf("Case %d:\n",test);
        while(q--)
        {
            scanf("%s",c);
            if(c[0] == 'I')
            {
                scanf("%d%d",&a,&b);
                update(1,0,d,a-1,b-1);
            }
            else
            {
                scanf("%d",&a);
                l = query(1,0,d,a-1);
                if(l%2 == 0)
                {
                    printf("%c\n",g[a-1]);
                }
                else
                {
                    if(g[a-1]=='0')printf("1\n");
                    else printf("0\n");
                }
            }
        }
    }

    return 0;
}
