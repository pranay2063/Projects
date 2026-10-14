//Sum in a range

//Segment Trees Basic Application of finding sum in a range

#include<bits/stdc++.h>

using namespace std;

int segtree[4*1000000];

int query(int left,int right,int l,int r,int index)
{

     if(left>r || right<l)
     return 0;

     else if(left>=l && right<=r)
          return segtree[index];

     int mid=(left+right)/2;

     return query(left,mid,l,r,2*index+1)+query(mid+1,right,l,r,2*index+2);

}

void update(int a[],int left,int right,int pos,int value,int index)
{

     if(left==right)
     {

          a[left]=value;

          segtree[index]=value;

          return ;

     }

     int mid=(left+right)/2;

     if(pos<=mid)
     update(a,left,mid,pos,value,2*index+1);

     else update(a,mid+1,right,pos,value,2*index+2);

     segtree[index]=segtree[2*index+1]+segtree[2*index+2];

}

void build(int a[],int left,int right,int index)
{

    if(left==right)
    {

        segtree[index]=a[left];

        return ;

    }

    int mid=(left+right)/2;

    build(a,left,mid,2*index+1);
    build(a,mid+1,right,2*index+2);

    segtree[index]=segtree[2*index+1]+segtree[2*index+2];

}

int main()
{

    int n,m,l,r,i,num[101];
    //char str[11];

    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
    scanf("%d",&num[i]);

    build(num,0,n-1,0);

    //update(num,0,n-1,2,3,0);

    while(m--)
    {

        //scanf("%s",str);

        scanf("%d%d",&l,&r);

        printf("%d\n",query(0,n-1,l-1,r-1,0));

    }

    return 0;

}




















