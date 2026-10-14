#include<bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int dp[MAX][MAX];

int main()
{

    //Complexity of this LCS algorithm is O(m*n)
    //https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
    //Space complexity can be reduced from O(m*n) to O(2*min(m,n))

    string a,b;
    cin>>a>>b; 

    if(a.length()<b.length())   swap(a,b);
    int m=a.length(),n=b.length();

    for(int i=0;i!=m;i++)
    {
        dp[0][i]=0;
        if(i<n) dp[i][0]=0;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }

    printf("The length of the LCS is %d.",dp[m][n]);

    return 0;

}

















































