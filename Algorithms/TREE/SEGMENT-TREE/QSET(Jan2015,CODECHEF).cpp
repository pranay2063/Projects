/*
 
   In this case,we don not need to find the sum_modulo_3 of each substring.
 
   It is because of the observation :
 
   For each segment , we find each prefix subsegment(substring) modulo 3.
 
   Now, if for any two prefix subsegment , sum modulo 3 is equal ,then there is a substring which is divisible by 3 between them.
   Eg.  A="23";
        A%3=2;
 
        B="2342";
        B%3=2;
        Then , "42" is the substring divisible by 3.
 
   Thus, for sum modulo 3 for each prefix subsegment and store count of remainders 0,1,2 in th segment;
   Final result can be computed by the finding the result below.
   result=(count[0]+1)C2 + count[1]C2 + count[2]C2;
 
   In case of 0 remainder , we must include empty substring in its count because any prefix may be divisible by 3.
 
*/
 
#include<bits/stdc++.h>
 
using namespace std;
 
struct QSET{
 
 
     long long segmentsum_mod_3;
 
     long long count[3];
 
};
 
QSET segtree[500000],senital;
 
//senital node works same as 0
 
void init(QSET &result)
{
 
    result.segmentsum_mod_3=0;
 
    for(long long i=0;i<3;i++)
    {
 
         result.count[i]=0;
 
    }
 
}
 
QSET merge(QSET left,QSET right)
{
 
    QSET result;
 
    init(result);
 
    result.segmentsum_mod_3=(left.segmentsum_mod_3+right.segmentsum_mod_3)%3;
 
    for(long long i=0;i<3;i++)
    {
 
        result.count[i] +=left.count[i];
 
        //we include all prefixes of left subsegment as above
 
        result.count[(i+left.segmentsum_mod_3)%3] += right.count[i];
 
        //all right prefixes are added to entire left subsegment(mind it entire one).
 
    }
 
    return result;
 
}
 
QSET query(char a[],long long left,long long right,long long l,long long r,long long index)
{
 
      if(left>r || right<l)
      return senital;
 
      else if(left>=l && right<=r)
           {
 
               /*
 
               QSET temp=segtree[index];
 
               cout<<"segment : "<<left+1<<" "<<right+1<<endl;
 
               cout<<temp.segmentsum_mod_3<<endl;
               for(int i=0;i<3;i++)
               printf("%lld ",temp.count[i]);
 
               cout<<endl;
               */
 
               return segtree[index];
 
           }
 
      long long mid=(left+right)/2;
 
      QSET temp = merge(query(a,left,mid,l,r,2*index+1),query(a,mid+1,right,l,r,2*index+2));
 
      /*
 
      cout<<"segment : "<<left+1<<" "<<right+1<<endl;
 
      cout<<temp.segmentsum_mod_3<<endl;
 
      for(int i=0;i<3;i++)
      printf("%lld ",temp.count[i]);
 
      cout<<endl;
 
      */
 
      return temp;
 
}
 
void update(char a[],long long left,long long right,long long pos,long long value,long long index)
{
 
    if(left==right)
    {
 
        segtree[index].segmentsum_mod_3=value%3;
 
        segtree[index].count[segtree[index].segmentsum_mod_3]=1;
        segtree[index].count[(segtree[index].segmentsum_mod_3+1)%3]=0;
        segtree[index].count[(segtree[index].segmentsum_mod_3+2)%3]=0;
 
    }
    else {
 
        long long mid=(left+right)/2;
 
        if(pos<=mid)
        update(a,left,mid,pos,value,2*index+1);
 
        else update(a,mid+1,right,pos,value,2*index+2);
 
        segtree[index]=merge(segtree[2*index+1],segtree[2*index+2]);
 
    }
 
}
 
void build(char a[],long long left,long long right,long long index)
{
 
      if(left==right)
      {
 
          segtree[index].segmentsum_mod_3=(a[left]-'0')%3;
          segtree[index].count[segtree[index].segmentsum_mod_3]=1;
 
      }
      else {
 
 
             long long mid=(left+right)/2;
 
             build(a,left,mid,2*index+1);
             build(a,mid+1,right,2*index+2);
 
             segtree[index]=merge(segtree[2*index+1],segtree[2*index+2]);
 
      }
 
}
 
long long divisible(QSET ans)
{
 
      long long result=0;
 
      for(long long i=0;i<3;i++)
      {
 
          long long temp=ans.count[i];
 
          //cout<<temp<<endl;
 
          if(i==0)
          temp++;
 
          result += temp*(temp-1)/2;
 
      }
 
      return result;
 
}
 
char str[100001];
 
int main()
{
 
      init(senital);
 
      long long n,m,l,r,i,type;
 
      scanf("%lld%lld",&n,&m);
      scanf("%s",str);
 
      build(str,0,n-1,0);
 
      //for(i=0;i<9;i++)
      //cout<<segtree[i].segmentsum_mod_3<<endl;
 
      /*
 
      QSET temp;
 
      temp.segmentsum_mod_3=1;
      for(i=0;i<3;i++)
      temp.count[i]=i;
 
      temp=merge(temp,senital);
 
      cout<<temp.segmentsum_mod_3<<endl;
 
      for(i=0;i<3;i++)
      printf("%lld ",temp.count[i]);
 
      cout<<endl;
 
      */
 
      while(m--)
      {
 
          scanf("%lld%lld%lld",&type,&l,&r);
 
          switch(type)
          {
 
              case 1 :
 
                         str[l-1]=char(r+48);
 
                         update(str,0,n-1,l-1,r,0);
 
                         //cout<<str<<endl;
 
                         break;
 
              case 2 :
 
                         QSET result=query(str,0,n-1,l-1,r-1,0);
 
                         //cout<<result.segmentsum_mod_3<<endl;
 
                         printf("%lld\n",divisible(result));
 
                         break;
 
          }
 
      }
 
      return 0;
 
}
 
 
 
