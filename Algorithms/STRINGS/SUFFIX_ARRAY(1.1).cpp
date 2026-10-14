
#include<bits/stdc++.h>

using namespace std;

#define MAX   65536
#define MAXLG 17

#define FIRST  first.first
#define SECOND first.second
#define THIRD  second

//we take a string and consider all its suffixes
//In order to consider all the suffixes , we do not need to take a vector of strings
//we can denote a suffix by its start index in its parent string

//If A=ababa , then
//S1 = ababa = 0
//S2 = baba  = 1
//S3 = aba   = 2
//S4 = ba    = 3
//S5 = a     = 4

string A;

//we are going to sort suffixes which are parts of the same string
//we sort them first by their starting 1 characters ,then by starting 2 characters ,then by starting 4 characters and so on ...
//In each step of sorting , we use the result computed in the previous step


vector<pair<pair<int,int>,int> >  L(MAX);  //we use the vector L to find sortindex at current step
int P[MAXLG][MAX];     //this holds the sortindex of the suffixes at all stages of sorting
int SA[MAX];           //this stores the sorted order of suffixes at the end
int step=0;

void build()
{

    //this function sorts the suffixes and stores their sorted order
    //complexity of this algorithm is O(N*logN*logN)
    //N*logN sorting is done for logN number of steps

    //this approach is simple to code for programming contests
    //still this is not the best known algorithm for suffix array construction

    int i,cnt;
    int N = A.length();

    //At step 0 , sort suffixes according to their first character by passing the value of the first character

    for(i=0;i!=N;i++) P[0][i]=A[i]-'a';

    for(step=1,cnt=1; cnt<N ;step++,cnt*=2)
    {

         //we use the sortindex of i and (i+cnt) at (step-1) to find sortindex of ith suffix at any value step
         //At any step , we are considering 2*cnt length prefix of the suffixes
         for(i=0;i<N;i++)
         {
             //L[i]=make_pair(make_pair(P[step-1][i],i+cnt<N?P[step-1][i+cnt]:-1),i);
             L[i].FIRST  = P[step-1][i];
             L[i].SECOND = i+cnt<N?P[step-1][i+cnt]:-1;
             L[i].THIRD  = i;
         }

         //sort the vector L
         sort(L.begin(),L.begin()+N);

         //assign the sortindex at this step to all the suffixes
         //for(i=0;i<N;i++) P[step][L[i].THIRD]=(i>0 && L[i].FIRST==L[i-1].FIRST && L[i].SECOND==L[i-1].SECOND)? P[step][L[i-1].THIRD] : i;

         for(i=0;i<N;i++)
         {
             if(i>0 && L[i].FIRST==L[i-1].FIRST && L[i].SECOND==L[i-1].SECOND)  P[step][L[i].THIRD]=P[step][L[i-1].THIRD];
             else P[step][L[i].THIRD]=i;
         }

    }

    //store the sorted array of suffixes at the end
    for(i=0;i<N;i++)  SA[i]=L[i].THIRD;

}

int LCP(int x,int y)
{

    //this function finds the length of longest common prefix of any two suffixes
    //this length can be expressed as sum of powers of 2
    //complexity of this approach is O(logN)

    int N = A.length();
    if(x==y) return (N-x);
    int ans=0;

    for(int i=step-1; i>=0 && x<N && y<N ;i--)
    {
        if(P[i][x]==P[i][y]) x+=1<<i , y+=1<<i , ans+=1<<i;
    }

    //cout<<ans<<endl;
    return ans;

}

int main()
{

    int t,i;

    scanf("%d",&t);

    // we have to find the number of distinct substrings in a string
    // if the length of the string is n , then total number of substrings is n*(n+1)/2

    // If you look through the prefixes of each suffix of a string, you have covered all substrings of that string
    // Now we have to remove the repeated prefixes
    // if we sort the above set of suffixes, we can skip the repeated prefixes easily

    while(t--)
    {

        cin>>A;
        int N = A.length();
        build();

        //Initially , ans = length(first suffix in sorted order)
        long long ans=N-SA[0];
        
        //All characters that are not part of the common prefix contribute to a distinct substring
        for(i=1;i<N;i++)  ans+=(N-SA[i])-LCP(SA[i-1],SA[i]);

        printf("Number of distinct substrings = %lld",ans);
        putchar('\n');

    }

    return 0;

}







































