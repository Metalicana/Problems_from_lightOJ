#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("o.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        stack <string> bacc;
        stack <string> forw;
        string g,h;
        printf("Case %d:\n",test);
        string cur="http://www.lightoj.com/";
        while(cin >> g && g!= "QUIT")
        {
            if(g == "VISIT")
            {
                bacc.push(cur);
                while(!forw.empty())forw.pop();
                cin >> h;
                cur = h;
                cout << cur << "\n";

            }
            else if(g == "BACK")
            {
                if(bacc.size()!=0)
                {
                    forw.push(cur);
                    cur = bacc.top();
                    cout << cur << "\n";
                    bacc.pop();
                }
                else printf("Ignored\n");
            }
            else
            {
                if(forw.size()!=0)
                {
                    bacc.push(cur);
                    cur = forw.top();
                    cout << cur << "\n";
                    forw.pop();

                }
                else printf("Ignored\n");
            }
        }
    }

    return 0;
}
