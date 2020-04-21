#include <bits/stdc++.h>
using namespace std;
int t;
char a[105],b[105];
int la,lb,i,j,m;
int LCS[105][105];
int main()
{

    scanf("%d",&t);
    for(int test=1; test<=t; test++)
    {
        scanf("%s%s",a,b);
        la = strlen(a);
        lb = strlen(b);
        string s[la+1][lb+1];
        for(int w=0; w<=la; w++)
        {
            for(int q=0; q<=lb; q++)
            {
                if(w == 0 || q == 0)
                {
                    LCS[w][q] = 0;
                    s[w][q] = "";
                }
                else if(a[w-1] == b[q-1])
                {
                    LCS[w][q] = 1 + LCS[w-1][q-1];
                    s[w][q] = s[w-1][q-1] + a[w-1];
                }
                else if(LCS[w-1][q] > LCS[w][q-1])
                {
                    LCS[w][q] = max(LCS[w-1][q],LCS[w][q-1]);
                    s[w][q] = s[w-1][q];
                }
                else if(LCS[w-1][q] < LCS[w][q-1])
                {
                    LCS[w][q] = max(LCS[w-1][q],LCS[w][q-1]);
                    s[w][q] = s[w][q-1];
                }
                else
                {
                    LCS[w][q] = max(LCS[w-1][q],LCS[w][q-1]);
                    s[w][q] = min(s[w][q-1],s[w-1][q]);
                }
            }
        }
        if(LCS[la][lb] == 0)printf("Case %d: :(\n",test);
        else
        {
            printf("Case %d: %s\n",test,s[la][lb].c_str());
        }

    }
    return 0;
}
