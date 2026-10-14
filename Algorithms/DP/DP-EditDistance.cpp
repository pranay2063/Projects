#include<bits/stdc++.h>
using namespace std;

#define scan(a)       scanf("%d",&a)
#define print(a)      printf("%d",a)

const int MAX = 2015;
int dp[MAX][MAX];

int main()
{

    //https://en.wikipedia.org/wiki/Edit_distance
    //Time complexity is O(m*n)
    //Space complexity can be reduced to O(2*min(m,n))

    int t,i,j;
    string a,b;
    scan(t); 

    while(t--)
    {

        //Dynamic Programming
        //Edit distance (also called Levenshtein distance)
        //Each insertion,deletion and substitution takes unit time
        cin>>a>>b;

        int n=a.length(),m=b.length();
        dp[0][0]=0;

        for(i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+1;
        for(i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+1;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
                //print(dp[i][j]);
                //putchar(' ');
            }
            //putchar('\n');
        }

        print(dp[n][m]);
        putchar('\n');

    }

    return 0;

}

















































#include<bits/stdc++.h>

using namespace std;

#define scan(a)       scanf("%d",&a)
#define print(a)      printf("%d",a)

const int MAX = 2015;

int dp[MAX][MAX];

int main()
{

    //https://en.wikipedia.org/wiki/Edit_distance

    //Time complexity is O(m*n)

    //Space complexity can be reduced to O(2*min(m,n))

    int t,i,j;
    string a,b;

    scan(t); 

    while(t--)
    {

        cin>>a>>b;

        //Dynamic Programming
        //Edit distance (also called Levenshtein distance)
        //Each insertion,deletion and substitution takes unit time

        int n=a.length(),m=b.length();

        dp[0][0]=0;

        for(i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+1;

        for(i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+1;

        for(i=1;i<=n;i++)
        {

            for(j=1;j<=m;j++)
            {

                if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];

                else dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));

                //print(dp[i][j]);
                //putchar(' ');

            }

            //putchar('\n');

        }

        print(dp[n][m]);

        putchar('\n');

    }

    return 0;

}

















































