#include <bits/stdc++.h>
using namespace std;
int n,m,q;
bool salsabil;
string g[100006];
pair <int,int> sizes[100006];
struct node
{
    bool endmark;
    node *next[12];
    node()
    {
        endmark = false;
        for(int w=0;w<12;w++)next[w]=NULL;
    }
}*root;
void insert_it(string g)
{
    int id;
    int len = g.size();
    node *cur = root;
    for(int w=0;w<len;w++)
    {
        id = g[w]-48;
        if(cur->next[id]==NULL)
        {
            cur->next[id] = new node();
        }
        if(cur->endmark == 1)salsabil=1;
        cur = cur->next[id];
    }
    if(cur->endmark == 1)salsabil=1;
    cur->endmark = true;
}
void delete_dis(node *root)
{
    for(int w=0;w<12;w++)
    {
        if(root->next[w])delete_dis(root->next[w]);
    }
    delete(root);
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int test=1;test<=t;test++)
    {

        root = new node();
        salsabil = 0;
        scanf("%d",&n);
        for(int w=0;w<n;w++)
        {
            cin >> g[w];
            sizes[w].first = g[w].size();
            sizes[w].second = w;
        }
        sort(sizes,sizes+n);
        for(int w=0;w<n;w++)
        {
            insert_it(g[sizes[w].second]);
        }
        if(salsabil==1)printf("Case %d: NO\n",test);
        else printf("Case %d: YES\n",test);
        delete_dis(root);
    }
    return 0;
}
