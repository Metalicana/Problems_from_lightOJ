#include <bits/stdc++.h>
using namespace std;//1-A 2-T 3-C 4-G
#define inf 1000000000
char c[52];
struct node
{
    int val[5],depth;
    node *poopoo[5];
    node()
    {
        //val = 0;
        for(int w=1;w<=4;w++)
        {
            poopoo[w]=NULL;
            val[w]=0;
        }
    }
};
node *root=NULL;
void init()
{
   root = new node();
}
int id_finder(char s)
{
    if(s == 'A')return 1;
    if(s == 'T')return 2;
    if(s == 'C')return 3;
    return 4;
}
void insert_it(char *x)
{
    int d =1;
    node *cur = root;
    int id;
    for(int w=0;x[w];w++)
    {
        cur->depth = d;
        d++;
        id = id_finder(x[w]);
        cur->val[id]++;
        if(cur->poopoo[id] == NULL)cur->poopoo[id] = new node();
        cur = cur->poopoo[id];
    }
}
int ans;
void traverse(node *cur)
{
    if(cur == NULL)return;
    ans = max(ans, cur->depth * cur->val[1]);
    ans = max(ans,cur->depth * cur->val[2]);
    ans = max(ans, cur->depth * cur->val[3]);
    ans = max(ans,cur->depth * cur->val[4]);
    traverse(cur->poopoo[1]);
    traverse(cur->poopoo[2]);
    traverse(cur->poopoo[3]);
    traverse(cur->poopoo[4]);
}
void free(node *cur)
{


    if(cur == NULL)return;
    free(cur->poopoo[1]);
    free(cur->poopoo[2]);
    free(cur->poopoo[3]);
    free(cur->poopoo[4]);
    delete(cur);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        scanf("%d",&n);
        init();
        ans= -inf;
        for(int w=0;w<n;w++)
        {
            scanf("%s",c);
            insert_it(c);
        }
        traverse(root);
        printf("Case %d: %d\n",test,ans);
        free(root);
    }
    return 0;
}
