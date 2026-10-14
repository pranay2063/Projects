
//Author : Pranay Ranjan(pranay2063)

//XMEN
//http://www.spoj.com/problems/XMEN/


#include<bits/stdc++.h>

using namespace std;

#define ll            long long
#define ull           unsigned long long
#define print(a)      printf("%d",a)
#define print2(a,b)   printf("%d %d",a,b)
#define print3(a,b,c) printf("%d %d %d",a,b,c)
#define line          putchar('\n')
#define scan(a)       scanf("%d",&a)
#define scan2(a,b)    scanf("%d%d",&a,&b)
#define scan3(a,b,c)  scanf("%d%d%d",&a,&b,&c)

/*****************STL**********************/

#define pb(a)         push_back(a)
#define pf(a)         push_front(a)
#define mp(a,b)       make_pair(a,b)
#define type(a)       typeof(a.begin())
#define set_it        set<int>::iterator
#define vector_it     vector<int>::iterator

/******************************************/

int main()
{

    //ios_base::sync_with_stdio(false);

    int t,i,mid,n,num;

    scan(t);

    //DP
    //LCS(Longest Common Subsequence) turned into LIS(Longest Increasing Subsequence)

    //In this problem, this can be done because all the numbers are from 1 to N
    //So, for the first sequence we store the order(index) of all the its elements

    //We apply LIS to the 2nd sequence based on their order in first sequence 
    //ie,if a and b are two elements of 2nd sequence such that b suceeds a
    //then if index of a is less than index of b in 1st sequence , then they form an increasing sequence

    while(t--)
    {

        scan(n);

        int a[n+1],b[n+1],temp[n+1];

        for(i=0;i<n;i++)
        {

            scan(num);

            a[num]=i;
	    //store the index of elements of 1st sequence

        }

        for(i=0;i<n;i++)
        {

            scan(b[i]);

        }

        int ans=0;

	//LIS

        for(i=0;i<n;i++)
        {

            int start=1,end=ans;

            while(start<=end)
            {

                if((start+end)&1) mid=(start+end)/2+1;

                else mid=(start+end)/2;

                if(a[b[temp[mid]]]<a[b[i]]) start=mid+1;

                else end=mid-1;

            }

            temp[start]=i;

            if(start>ans) ans=start;

        }

	//Ultimately,LIS gives the LCS of two sequences

        print(ans);

        line;

    }

    return 0;

}













































