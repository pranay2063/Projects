
#include<bits/stdc++.h>
using namespace std;

const int MAX = 5005;
int cnt[MAX];

void z_function(string &a,vector<int> &Z)
{

    //this function calculates Z-function for a string

    //Z-function is LCP of a string with all its suffixes

    //complexity of calculating Z-function is O(N)

    //to compute Z[i] , we must iteratively compute :

    //(1) all Z[2],...,Z[i-1]

    //(2) the boundaries L,R of the rightmost Z-box found starting someplace in 2...(i-1).

    int i,j,L=0,R=0,N=a.length();
    Z[0]=a.length();

    for(i=1;i!=N;i++)
    {

         if(i>R)
         {
               //there is no rightmost Z-box till i

               //we will manually compare a[i...] to a[0...] to find Z[i]

               //we will update L and R as rightmost Z-box is now at i

               L=i; R=i;

               while(R<N && a[R-L]==a[R]) R++;

               R--;
               Z[i]=R-L+1;
         }
         else {

                    //a[L...R] = a[0...(R-L)]
                    //a[i] = a[i-L]

                    int k=i-L;
                    if(Z[k]<(R-i+1)) Z[i]=Z[k];

                    else {
                        
                             //if Z[k]==(R-i+1) , then Z[i] can be greater than or equal to Z[k]

                             //we will have to confirm by checking manually

                             L=i;
                             R++;

                             while(R<N && a[R-L]==a[R]) R++;

                             R--;
                             Z[i]=R-L+1;
                        
                    }//end of inner else

         }//end of outer else

    }//end of for loop

}

void z_emaxx(string &a,vector<int> &Z)
{

    //this function has been adopted from emaxx.ru

    //this function calculates Z-function for a string

    //Z value of any suffix starting at i (Z[i]) is the LCP of parent string(a) with itself

    //LCP is the longest common prefix of two strings

    //Here by LCP , we mean length of LCP

    int i,L=0,R=0,N=a.length();

    Z[0]=a.length();

    for(i=1;i!=N;i++)
    {

         //initial approximation of Z[i]

         if(i<=R) Z[i]=min((R-i+1),Z[i-L]);

         //manually check if Z[i] can be extended

         while((i+Z[i])<N && a[Z[i]]==a[i+Z[i]]) Z[i]++;

         //if Z-box at i exceeds the existing R ,then update the value of current L and R

         if((i+Z[i]-1)>R) L=i,R=i+Z[i]-1;

    }

}

void count_find(string &a)
{

    //this function finds the count(cnt) of different distinct substrings using Z-algorithm

    int i,j,N=a.length();

    for(i=0;i<=N;i++) cnt[i]=0;

    for(i=0;i!=a.length();i++)
    {

         //for(i=0;i<N;i++) Z[i]=0,temp[i]=0;

         vector<int> Z(MAX,0),temp(MAX,0);

         //apply Z-algorithm on each suffix of the given string

         string suffix=a.substr(i,N-i);

         z_emaxx(suffix,Z);

         for(j=0;j<N;j++)  temp[Z[j]]++;

         for(j=N;j>=1;j--) temp[j]+=temp[j+1];

         for(j=1;j<=N;j++) cnt[temp[j]]++;

    }

    //till now cnt[i] means number of substrings which occur "atleast" i times

    //this is the cumulative cnt array

    //we will convert it suct that cnt[i] will represent number of substrings occuring "exactly" i times

    //it can be done as : cnt[i]=cnt[i]-cnt[i+1]

    for(i=1;i<N;i++) cnt[i]-=cnt[i+1];

}

void print_count(string a)
{

    for(int i=1;i<=a.length();i++)
        printf("cnt[%d]-->%d\n",i,cnt[i]);

    putchar('\n');

}

int main()
{

    int t;
    string a;
    scanf("%d",&t);

    while(t--)
    {

         cin>>a;
         count_find(a);
         print_count(a);

    }

    return 0;

}
































