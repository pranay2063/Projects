//Application of segment trees

// Finding the sum of any two indices i and j in any given range such that sum is maximum for any other pair

#include<bits/stdc++.h>

using namespace std;

struct node{


     int first,second;

     //Here , any node stores maximum and second maximum in the given range

     //While merging two nodes maximum and second maximum are updated

};

node segtree[4*1000000],senital;

node query(int left,int right,int l,int r,int index)
{

     // function can return a structure variable

     if(left>r || right<l)
     return senital;

     else if(left>=l && right<=r)
          return segtree[index];

          else {

                    int mid=(left+right)/2;

                    node a=query(left,mid,l,r,2*index+1);
                    node b=query(mid+1,right,l,r,2*index+2);

                    node ans;

                    //While merging two nodes maximum and second maximum are updated

                    ans.first=max(a.first,b.first);

                    if(ans.first==a.first)
                    {

                         ans.second=max(a.second,b.first);

                    }
                    else {

                             ans.second=max(a.first,b.second);

                         }

                    //printf("%d\n",ans.first+ans.second);

                    return ans;

               }

}

void update(int arr[],int left,int right,int pos,int value,int index)
{

     if(left==right)
     {

         segtree[index].first=value;

         segtree[index].second=INT_MIN;

     }
     else {

               int mid=(left+right)/2;

               if(pos<=mid)
               update(arr,left,mid,pos,value,2*index+1);

               else update(arr,mid+1,right,pos,value,2*index+2);

               node a=segtree[2*index+1],b=segtree[2*index+2];

               segtree[index].first=max(a.first,b.first);

               if(segtree[index].first==a.first)
               {

                  segtree[index].second=max(a.second,b.first);

               }
               else {

                        segtree[index].second=max(a.first,b.second);

                    }

          }

}

void build(int arr[],int left,int right,int index)
{

     if(left==right)
     {

         segtree[index].first=arr[left];

         segtree[index].second=INT_MIN;

         return ;

     }

     int mid=(left+right)/2;

     build(arr,left,mid,2*index+1);
     build(arr,mid+1,right,2*index+2);

     node a=segtree[2*index+1],b=segtree[2*index+2];

     segtree[index].first=max(a.first,b.first);

     if(segtree[index].first==a.first)
     {

         segtree[index].second=max(a.second,b.first);

     }
     else {

               segtree[index].second=max(a.first,b.second);

          }

}

int main()
{

    senital.first=senital.second=INT_MIN;

    int n,m,i,l,r,k;
    char type;

    scanf("%d",&n);

    int num[n];

    for(i=0;i<n;i++)
    scanf("%d",&num[i]);

    build(num,0,n-1,0);

    //for(i=0;i<10;i++)
    //printf("%d %d\n",segtree[i].first,segtree[i].second);

    scanf("%d",&m);

    while((k=getchar())!='\n' && k!=EOF);

    while(m--)
    {

        scanf("%c%d%d",&type,&l,&r);

        while((k=getchar())!='\n' && k!=EOF);

        switch(type)
        {

            case 'U' :

                        num[l-1]=r;

                        update(num,0,n-1,l-1,r,0);

                        break;

            case 'Q' :

                        node ans=query(0,n-1,l-1,r-1,0);

                        printf("%d\n",ans.first+ans.second);

                        break;

        }

    }

    return 0;

}























