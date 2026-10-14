#include<bits/stdc++.h>
 
using namespace std;
 
int divide_max(int a[],int left,int right)
{
 
	//Time Complexity is same as sequential search
	//Time Complexity is O(n) which can be found using recurrence relation
	//Actual complexity is T(n)=3/2*n-2 
	//Recurrence relation is T(n)=T(n/2)+2
 
	if(left==right)
		return a[left];
 
	else {
 
		      int mid=(left+right)/2;
		      return max(divide_max(a,left,mid),divide_max(a,mid+1,right));
 
	     }
 
}
 
int brute_max(int a[],int size)
{
 
    int max=INT_MIN;
    for(int i=0;i<size;i++)
    {
       if(a[i]>max)
       	max=a[i];
    }
 
    return max;
 
}
 
int main()
{
 
	int n;
	scanf("%d",&n);
 
	int *a;
	a=(int *)malloc(n*sizeof(int));
 
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
 
	printf("%d\n",divide_max(a,0,n-1));
	printf("%d\n",brute_max(a,n));
 
	return 0;
 
}	

/*
stdin copy
5
100 100 100 100 100
stdout copy
100
100
*/ 
