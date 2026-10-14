#include<bits/stdc++.h>

using namespace std;
const int MAX = 1000001;

int a[MAX],temp[MAX],pre[MAX];

int main()
{

    //https://en.wikipedia.org/wiki/Longest_increasing_subsequence
    //Time complexity of this algorithm is O(n*logn)

    int n,i;
    scanf("%d",&n);

    for(i=0;i<n;i++)  scanf("%d",&a[i]);

    int ans=0;
    temp[0]=0; 

    //temp[j]=i means j is the length of a subsequence whose end element is at index i of input array
    //pre[] array stores the predecessor of a[i] in its increasing subsequence

    for(i=1;i<n;i++)
    {
        //Binary search to find the length new subsequence ending at a[i]
        //This one is an online algorithm
        int start=0,end=ans,mid;

        while(start<=end)
        {
            mid=(start+end)/2;
            if(a[temp[mid]]<a[i]) start=mid+1;
            else end=mid-1;
        }

        int newl=start;

        temp[newl]=i;
        pre[i]=temp[newl-1];

        if(newl>ans) ans=newl;
        //cout<<start<<endl;

    }

    printf("%d",ans+1);
    putchar('\n');

    vector<int> lis;
    int k=temp[ans];

    for(i=0;i<ans+1;i++)
    {
        lis.push_back(a[k]);
        k=pre[k];
    }

    for(i=lis.size()-1;i>=0;i--)
    printf("%d ",lis[i]);

    return 0;

}





