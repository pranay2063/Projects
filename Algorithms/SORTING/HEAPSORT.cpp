//Time Complexity of heapsort is nlog(n)

#include<bits/stdc++.h>
using namespace std;
 
void insert_heap(int a[],int &size,int value)
{
 
    //Insertion in a heap
    //We increase the size of heap by 1 and insert the value into it
    //After inserting into it,we shift the element to its proper position
    //a[size] is the array for heap
 
    size++;
    a[size]=value;
    int parent=size/2,child=size;
 
    while(a[parent]<a[child] && parent>=1)
    {
       swap(a[parent], a[child]);
       child=child/2;
       parent=parent/2;
    }
 
}
 
void heapify_bottom(int a[],int root,int &size)
{
 
    // Complexity is O(n)
    // It is a bottom-up approach because we create heap starting from bottom till root
    // a[size] is the array for heap
 
    int parent=root;
    int left=2*parent, right=2*parent+1;
 
    while(left<=size && right<=size)
    {
        if(a[parent]>=a[left] && a[parent]>=a[right])  break;       
        else if(a[left]>a[right])
             {
                 swap(a[parent],a[left]);
                 parent=left;
             }
             else {
                      swap(a[parent],a[right]);
                      parent=right;
                  }
 
        left=2*parent;
        right=2*parent+1;          
    }
 
    if(left<=size && a[parent]<a[left]) swap(a[left],a[parent]);
 
}   
 
int delete_heap(int a[],int root,int &size)
{
 
    // a[size] is the array for heap
    int temp=a[1];
    a[1]=a[size];
    size--;
 
    heapify_bottom(a,1,size);
 
    return temp;
}
 
void make_heap(int a[],int size)
{
 
    // Complexity is O(n)
    // It is a bottom-up approach because we create heap starting from bottom till root
    // Also , leaf nodes is a heap already
    // a[size] is the array for heap
 
    for(int i=size/2;i>=1;i--) heapify_bottom(a,i,size);
 
}
 
void heap_sort(int a[],int size)
{
 
    make_heap(a,size);
 
    for(int i=size;i>=1;i--)
    {
        int temp_size=i;
        int temp=delete_heap(a,1,temp_size);
        temp_size++;
        a[temp_size]=temp;
    }
 
}
 
int main(void)
{
 
    int n,i;
    cin>>n;
 
    int a[n+1];
 
    for(i=1;i<=n;i++)
     cin>>a[i];
 
    heap_sort(a,n);
 
    //cout<<"SORTED DATA : ";
    for(i=1;i<=n;i++) cout<<a[i]<<endl;
    cout<<endl;
 
    insert_heap(a,n,33);
    heap_sort(a,n);
 
    cout<<"SORTED DATA : ";
    for(i=1;i<=n;i++) cout<<a[i]<<" ";
 
    return 0;
 
}    

/*
stdin copy
5
5
3
6
7
1
stdout copy
1
3
5
6
7

SORTED DATA : 1 3 5 6 7 33 
*/
