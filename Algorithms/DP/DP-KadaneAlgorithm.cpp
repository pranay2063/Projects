// Dynamic Programming(DP)
// Application of the Kadane's Algorithm to find the largest subarray sum
// In the actual implementation,Kadane assumed that atleast one of the elements of the array is positive
// But we can modify it to consider the case when all elements are negative
// In that case , we just have to print the maximum element

#include<bits/stdc++.h>
using namespace std;

void KADANE_ALGORITHM()
{

    int n,i,max_so_far,max_ending_here,max_element;
    scanf("%d",&n);

    int num[n];

    for(i=0;i<n;i++)
    scanf("%d",&num[i]);

    //initialise max_so_far,max_element=INT_MIN and max_ending_here=0

    max_so_far=0;
    max_ending_here=0;
    max_element=INT_MIN;

    for(i=0;i<n;i++)
    {

        max_ending_here=max(max_ending_here+num[i],0);
        max_so_far=max(max_so_far,max_ending_here);
        max_element=max(max_element,num[i]);

    }

    if(max_so_far==0)
    max_so_far=max_element;

    printf("%d\n",max_so_far);

}

int main()
{

    KADANE_ALGORITHM();
    return 0;

}
















