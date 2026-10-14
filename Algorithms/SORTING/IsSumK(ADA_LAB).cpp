// To find whether sum of any two numbers in the array has a given sum k or not if array is sorted already
// Time complexity is O(n)
 
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 
    int i,n,k;
    scanf("%d",&n);
 
    //input is already sorted in ascending order
    int *a;
    a=(int *)malloc(n*sizeof(int));
 
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
 
    bool flag=false;
    scanf("%d",&k);
 
    int start=0,end=n-1;
    while(start<=end)
    {
        if(a[start]+a[end]==k)
        {
            flag=true;
            break;
        }    
        else if(a[start]+a[end]<k)
             start++;
             
             else end--;
 
    }
 
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 
    return 0;
 
}    

/*
stdin copy
5
1 3 4 5 8
3

stdout copy
NO
*/
