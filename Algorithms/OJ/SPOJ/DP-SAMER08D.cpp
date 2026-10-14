//http://www.spoj.com/problems/SAMER08D/

#include<bits/stdc++.h>
 
using namespace std;
 
#define ll            long long
#define ull           unsigned long long
#define print(a)      printf("%d",a)
#define print2(a,b)   printf("%d %d",a,b)
#define print3(a,b,c) printf("%d %d %d",a,b,c)
#define line          putchar('\n')
#define scan(a)       scanf("%d",&a)
#define scan2(a,b)    scanf("%d%d",&a,&b)
#define scan3(a,b,c)  scanf("%d%d%d",&a,&b,&c)
 
/*****************STL**********************/
 
#define pb(a)         push_back(a)
#define pf(a)         push_front(a)
#define mp(a,b)       make_pair(a,b)
#define type(a)       typeof(a.begin())
#define set_it        set<int>::iterator
#define vector_it     vector<int>::iterator
 
/******************************************/
 
const int MAX = 1001;
 
int dp[MAX][MAX],ans[MAX][MAX];
 
int main()
{
 
    //ios_base::sync_with_stdio(false);
 
    int k,i,j;
    string a,b;
 
    //DP
 
    while(1)
    {
 
        scan(k);
 
        if(k==0) break;
 
        cin>>a>>b;
 
        dp[0][0]=ans[0][0]=0;
 
        int n=a.length(),m=b.length();
 
        for(i=1;i<=n;i++) dp[i][0]=ans[i][0]=0;
 
        for(i=1;i<=m;i++) dp[0][i]=ans[0][i]=0;
 
        //dp[i][j] stores the length  of common segment greater than k and ending at a[i] & b[j]
        //ans[i][j] stores the optimal solution till a[i] & b[j]
        //the algorithm has 2 cases for a[i]==b[j] and a[i]!=b[j]
        //the recurrence relation for the two cases can be seen in the code below
 
        //one of the best DP problem related to LCS
 
        for(i=1;i<=n;i++)
        {
 
            for(j=1;j<=m;j++)
            {
 
                //cout<<ans[i][j];
 
                //tricky test case : 6 aaabca aaabcaabca
 
                if(a[i-1]==b[j-1])
                {
 
                    dp[i][j]=dp[i-1][j-1]+1;
 
                    int temp=dp[i][j];
 
                    if(temp>k) //ans[i][j]=max(ans[i-1][j-1]+1,max(ans[i-k][j-k]+k,max(ans[i][j-temp],ans[i-temp][j])));
                    ans[i][j]=max(ans[i-1][j-1]+1,ans[i-k][j-k]+k);
 
                    else if(temp==k)
                         ans[i][j]=max(ans[i-1][j-1],ans[i-k][j-k]+k);
 
                         else ans[i][j]=ans[i-1][j-1];
 
                    ans[i][j]=max(ans[i][j],max(ans[i-1][j],ans[i][j-1]));
 
                }
 
                else {
 
                          dp[i][j]=0;
                          ans[i][j]=max(ans[i-1][j-1],max(ans[i-1][j],ans[i][j-1]));
 
                     }
 
                //cout<<ans[i][j]<<" ";
 
            }
 
            //cout<<endl;
 
        }
 
        print(ans[n][m]);
 
        line;
 
    }
 
    return 0;
 
}
 
 
 
 
