/*

   Purpose : A C++ program to convert a given array of elements in random order to maxheap and
             discuss complexities of different approaches that can be chosen.

*/

#include<bits/stdc++.h>

using namespace std;

class max_heap{

             //binary heap is a complete binary tree
             int size;
             int *a;//=(int *)malloc((size+1)*sizeof(int));

             public :

             max_heap(int a[],int size);

             void restore_down(int root);
             void restore_up(int );
             void top_to_down();
             void bottom_up();
             void heap_sort();
             void print();

};

max_heap :: max_heap(int b[],int len)
{

    //max_heap::
    size=len;
    a=(int *)malloc((size+1)*sizeof(int));

    for(int i=0;i<=size;i++)
      //max_heap::
      a[i]=b[i];

}

void max_heap :: print()
{

    for(int i=1;i<size;i++)   cout<<a[i]<<endl;
    cout<<endl;

}

void max_heap :: top_to_down()
{
   
     for(int i=2;i<=size;i++)
        restore_up(i);

}

void max_heap :: restore_up(int size)
{

     int child=size,parent=size/2;
     while(a[parent]<a[child] && parent>=1)
     {
         swap(a[parent],a[child]);
         child=child/2;
         parent=parent/2;
     }

}

void max_heap :: bottom_up()
{
     //there is no need to call restore_down for leaf nodes
     for(int i=size/2;i>=1;i--)
        restore_down(i);

}

void max_heap :: restore_down(int root)
{

     int left=2*root,right=left+1;

     while(left<size && right<size)
     {
         if(a[root]>=a[left] && a[root]>=a[right]) break;
         else if(a[left]>=a[right])
              {
                   swap(a[left],a[root]);
                   root=left;
              }
              else {
                        swap(a[right],a[root]);
                        root=right;
                   }

         left=2*root;
         right=left+1;
     }

     if(left<size && a[left]>a[root])  swap(a[left],a[root]);

}

void max_heap :: heap_sort()
{

    int temp=size;
    bottom_up();

    for(int i=2;i<temp;i++)
    {
        swap(a[1],a[size-1]);
        --size;
        restore_down(1);
    }

    size=temp;
}

int main()
{

    int a[]={INT_MAX,34,56,78,89,90,134,56};

    max_heap obj(a,8);
   
    obj.print();
    obj.bottom_up();
    obj.print();
    obj.heap_sort();
    obj.print();

    return 0;

}










