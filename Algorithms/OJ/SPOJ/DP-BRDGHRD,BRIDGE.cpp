//Author : Pranay Ranjan(pranay2063)

//http://www.spoj.com/problems/BRDGHRD/
//http://www.spoj.com/problems/BRIDGE/


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

const int MAX = 1001;

int temp[MAX];

int main(int argc, char*argv[])
{

    //ios_base::sync_with_stdio(false);

    int t,i,n;

    scan(t);

    //DP
    //LIS (Longest Increasing Subsequence)

    while(t--)
    {

        scan(n);

        int temp1[n],temp2[n],mid;

        for(i=0;i<n;i++) scan(temp1[i]);

        for(i=0;i<n;i++) scan(temp2[i]);

        vector<pair<int,int> > a;

        for(i=0;i<n;i++)
        {

            a.push_back(mp(temp1[i],temp2[i]));

        }

	//sort points of one end in ascending order
	//find the LIS of the corresponding points on the other end
	//this LIS is the answer ,ie, number of non-cutting edges 

        sort(a.begin(),a.end());

        int ans=0;

        for(i=0;i<n;i++)
        {

            int start=1,end=ans;

            while(start<=end)
            {

                if((start+end)&1) mid=(start+end)/2;

                else mid=(start+end)/2;

                if(a[temp[mid]].second<=a[i].second)
                start=mid+1;

                else end=mid-1;

            }

            temp[start]=i;

            if(start>ans) ans=start;

        }

        print(ans);

        line;

    }

    return 0;

}













































