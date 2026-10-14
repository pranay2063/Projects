//Code Monk(Arrays) , Hackerearth

//Find the sub-array from the given array such that sum of all the elements of that sub-array gives
//the value equal to X , in linear time i.e O(N).

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX  = 1000005;
int a[MAX];

int main()
{
    int t,i;
    ll n,x;
    scanf("%d",&t);
    
    while(t--)
    {
    	  //n is the number of elements in the array
    	  //x is the given value
    	  scanf("%lld%lld",&n,&x);
    	
    	  for(i=0;i<n;i++)  scanf("%lld",&a[i]);
    	
    	  bool ans=false;
    	  ll sum=0,start=-1;
 
    	  for(i=0;i<n;i++){
    		
    		    sum+=a[i];
    		    if(sum>x)
    		    {
    			      while(sum>x)  sum-=a[++start];    //remove elements from the beginning
    			
    			      if(sum==x) 
    			      {
    				        ans=true;
    				        break;
    			      }
    		    }
    		    else if(sum==x)
    			       {
    			 	          ans=true;
    			 	          break;
    			       }
    			 
    		
    	  }
    	
    	  if(ans) cout<<"YES"<<"\n";
    	  else cout<<"NO"<<"\n";
    	
    }
    
    return 0;
}
