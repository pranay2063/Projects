//Insertion sort for sorting data in ascending order
//For any index or location, data before it is sorted
//We insert element at any index i at its appropriate index j so that now the till the index i is sorted
// Time Complexity is O(n*n) for worst case

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a)
{

     int i,j;
     for(i=1;i<a.size();i++)
     {
          int temp=a[i];
          for(j=i-1;j>=0 && temp<a[j];j--)   a[j+1]=a[j];
          a[j+1]=temp;
     }

}

int main()
{

     int n,i,num;
     vector<int> a;
     scanf("%d",&n);

     for(i=0;i<n;i++)
     {
         scanf("%d",&num);
         a.push_back(num);
     }

     insertion_sort(a);
     printf("SORTED DATA : \n");

     for(i=0;i<n;i++)
     printf("%d ",a[i]);

     return 0;


}











