#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<long long, long long >
#define ll long long
#define lcm(a,b) (a)/__gcd((a),(b))*(b)
#define pb push_back
#define sz size()
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);i++)
#define x first
#define y second
#define maxn 100000
#define mod 1000000007
#define pi (2.0*acos(0.0))
#define endl '\n'
#define trace(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int m,n,row,col;

int mxRank;
// Structure to store information of a suffix
struct suffix
{
    int index; // To store original index
    int rank[2]; // To store ranks and next rank pair
};
// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
void countSort(suffix a[],int q, int n)
{
  suffix b[n];
  int i,count[n+27];
  memset(count,0,sizeof count);
  for(int i=0;i<n;i++)
  {
    count[a[i].rank[q]]++;
  }
  for(i=1;i< n+27;i++)count[i]+=count[i-1];

  for(i = n-1; i >=0; i--)
  {
    b[count[a[i].rank[q]]-1]=a[i];
    count[a[i].rank[q]]--;
  }
  for(i=0;i<n;i++)a[i]=b[i];
}
void sortThem(suffix a[],int n)
{
  int p = 1,i;
  for(i=1;i>=0;i--)
  {
    countSort(a, i,  n);
  }
}
int *buildSuffixArray(char *txt, int n)
{
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];

    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabatically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a'+1;
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): 0;
    }

    // Sort the suffixes using the comparison function
    // defined above.
  //  sort(suffixes, suffixes+n, cmp);

    sortThem(suffixes,n);
    // At this point, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on
    int ind[n];  // This array is needed to get the index in suffixes[]
                 // from original index.  This mapping is needed to get
                 // next suffix.
    for (int k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and index values to first suffix
        int rank = 1;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        // Assigning rank to suffixes
        for (int i = 1; i < n; i++)
        {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        // Assign next rank to every suffix
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: 0;
        }

        // Sort the suffixes according to first k characters
        //sort(suffixes, suffixes+n, cmp);
        sortThem(suffixes,n);
    }

    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;

    // Return the suffix array
    return  suffixArr;
}
int *kasai(char *txt, int *suffixArr,int n)
{


    int *lcp = new int[n];
    for(int i=0;i<n;i++)lcp[i]=0;

    // An auxiliary array to store inverse of suffix array
    // elements. For example if suffixArr[0] is 5, the
    // invSuff[5] would store 0.  This is used to get next
    // suffix string from suffix array.
    int invSuff[n]={0};

    // Fill values in invSuff[]
    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;

    // Initialize length of previous LCP
    int k = 0;

    // Process all suffixes one by one starting from
    // first suffix in txt[]
    for (int i=0; i<n; i++)
    {
        /* If the current suffix is at n-1, then we don’t
           have next substring to consider. So lcp is not
           defined for this substring, we put zero. */
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }

        /* j contains index of the next substring to
           be considered  to compare with the present
           substring, i.e., next string in suffix array */
        int j = suffixArr[invSuff[i]+1];

        // Directly start matching from k'th index as
        // at-least k-1 characters will match
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;

        lcp[invSuff[i]] = k; // lcp for the present suffix.

        // Deleting the starting character from the string.
        if (k>0)
            k--;
    }

    // return the constructed lcp array

    return lcp;
}
void solve(int test)
{
  char x[10005];
  scanf("%s",x);
  int lim1,lim2;
  scanf("%d%d",&lim1,&lim2);
  n = strlen(x);
  int *suffixArray = buildSuffixArray(x,n);
  int *lcp = kasai(x,suffixArray,n);
  int ans = 0;
  int lcpCpy[n];
  for(int i=0;i<n;i++)lcpCpy[i] = lcp[n-i-1];
  int cumsum[n+1]={0};
  for(int i=0;i<n;i++)
  {
    if(i > 0)cumsum[lcpCpy[i]]--;
    cumsum[n-suffixArray[i]]++;
  }
  for(int i=n-1;i>=0;i--)cumsum[i]+=cumsum[i+1];
  for(int i=lim1;i<=lim2;i++)ans+=cumsum[i];
  printf("Case %d: %d\n",test,ans);


}
void test()
{
  int t;
  scanf("%d",&t);
  for(int test=1;test<=t;test++)
  {
    solve(test);
  }
}
int main()
{

  //freopen("o.txt","w",stdout);
  test();
  return 0;
}
