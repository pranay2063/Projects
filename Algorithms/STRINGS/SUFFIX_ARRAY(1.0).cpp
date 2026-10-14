
#include<bits/stdc++.h>

using namespace std;

namespace SUFFIX_ARRAY
{

    //this approach is simple to code for programming contests
    const int MAXN=100001;
    int i,j;

    //we are going to sort suffixes which are parts of the same string
    //we sort them first by their starting 1 characters ,then by starting 2 characters ,then by starting 4 characters and so on ...
    //In each step of sorting , we use the result computed in the previous step
    //we can denote a suffix by its start index in its parent string
    
    int N,cnt;

    //sa[] stores the sorted order of suffixes at any step of sorting
    //pos[] stores of different suffixes starting at any index i
    //temp[] holds ranks based of sorting at any step
    //lcp[] stores LCP of consecutive suffixes in sorted order at the end

    int sa[MAXN],pos[MAXN],temp[MAXN],lcp[MAXN];
    string A;

    bool cmp(int i,int j)
    {
        //custom comparison function for sort()
        if(pos[i]!=pos[j]) return (pos[i]<pos[j]);
        i+=cnt;
        j+=cnt;

        return (i<N && j<N)?(pos[i]<pos[j]):(i>j);
    }

    void buildSA()
    {

        //this function sorts the suffixes and stores their sorted order
        //complexity of this algorithm is O(N*logN*logN)
        //N*logN sorting is done for logN number of steps

        temp[0]=0;
        N=A.length();

        for(i=0;i<N;i++) sa[i]=i,pos[i]=A[i]-'a';

        for(cnt=1;;cnt*=2)
        {
            sort(sa,sa+N,cmp);
            for(i=0;i<N-1;i++) temp[i+1]=temp[i]+cmp(sa[i],sa[i+1]);
            for(i=0;i<N;i++)   pos[sa[i]]=temp[i];
            if(temp[N-1] == N-1) break;
        }

    }

    void buildLCP()
    {
        //this function computes LCP of suffixes
        //lcp[] is any array of length (N-1) to store LCP of suffixes which are in sorted order
        //lcp[i] denotes length of LCP of sa[i] and sa[i+1]

        for(i=0;i<N-1;i++)
        {
            int len=0;
            for(int x=sa[i],y=sa[i+1] ;A[x+len]==A[y+len];) len++;
            lcp[i]=len;
        }
    }

}// end of namespace SUFFIX_ARRAY

using namespace SUFFIX_ARRAY;

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

        buildSA();
        buildLCP();

        //Initially , ans = length(first suffix in sorted order)

        long long ans=N-sa[0];
        //All characters that are not part of the common prefix contribute to a distinct substring

        for(i=0;i<N-1;i++)  ans+=(N-sa[i+1])-lcp[i];

        printf("Number of distinct substrings = %lld",ans);
        putchar('\n');

    }

    return 0;

}




















































