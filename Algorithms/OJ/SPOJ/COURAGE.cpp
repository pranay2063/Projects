// Segment trees -range minimum query and range  sum

// http://www.spoj.com/problems/COURAGE/

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define INTMAX 1000000007

ll segsum[4*100000];
ll segrmq[4*100000];

ll sum(ll left,ll right,ll l,ll r,ll index)
{

   if(right<l || left>r)
   return 0;

   else if(l<=left && r>=right)
        return segsum[index];

        else {

                 ll mid=(left+right)/2;

                 return sum(left,mid,l,r,2*index+1)+sum(mid+1,right,l,r,2*index+2);

             }

}

ll rmq(ll left,ll right,ll l,ll r,ll index)
{

   if(right<l || left>r)
   return (ll)INTMAX;

   else if(l<=left && r>=right)
        return segrmq[index];

        else {

                 ll mid=(left+right)/2;

                 return min(rmq(left,mid,l,r,2*index+1),rmq(mid+1,right,l,r,2*index+2));

             }

}

void update(ll a[],ll left,ll right,ll pos,ll value,ll index)
{

   if(left==right)
   {

       segsum[index]=value;
       segrmq[index]=value;

   }
   else {

       ll mid=(left+right)/2;

       if(pos<=mid)
       update(a,left,mid,pos,value,2*index+1);

       else update(a,mid+1,right,pos,value,2*index+2);

       segsum[index]=segsum[2*index+1]+segsum[2*index+2];
       segrmq[index]=min(segrmq[2*index+1],segrmq[2*index+2]);

   }

}

void build(ll a[],ll left,ll right,ll index)
{

   if(left==right)
   {

       segsum[index]=a[left];
       segrmq[index]=a[left];

   }
   else {

       ll mid=(left+right)/2;

       build(a,left,mid,2*index+1);
       build(a,mid+1,right,2*index+2);

       segsum[index]=segsum[2*index+1]+segsum[2*index+2];
       segrmq[index]=min(segrmq[2*index+1],segrmq[2*index+2]);

   }

}

int main()
{

   ll i,n,q,l,r;
   char str[15];

   scanf("%lld",&n);

   ll a[n];

   for(i=0;i<n;i++)
   scanf("%lld",&a[i]);

   build(a,0,n-1,0);

   //for(i=0;i<20;i++)
   //cout<<segrmq[i]<<" "<<segsum[i]<<endl;

   scanf("%lld",&q);

   while(q--)
   {

      scanf("%s%lld%lld",str,&l,&r);

      switch(str[0])
      {

         case 'E' : a[r]-=l;

                    update(a,0,n-1,r,a[r],0);

                    //for(i=0;i<20;i++)
                    //cout<<segrmq[i]<<" "<<segsum[i]<<endl;

                    break;

         case 'G' : a[r]+=l;

                    update(a,0,n-1,r,a[r],0);

                    break;

         case 'C' : printf("%lld\n",sum(0,n-1,l,r,0)-rmq(0,n-1,l,r,0));

                    break;

      }

   }

   return 0;

}


























