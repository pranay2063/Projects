//http://www.spoj.com/problems/RANJAN02/

//Recurrence relation in this case is T(n)=3*T(n-1)+2
//T(1)=2
 
//In this problem , we need to take care of way recurrence is being defined 
//Here T(n) is number of moves for transferring n pegs from A -> C
//So , T(n-1) is number of moves to transfer (n-1) pegs from A -> C
//Moving (n-1) pegs from A -> C is same as moving them from C -> A
 
//So, depending upon what T(n) represents above relation comes out
 
//One of the basic  Q. of finding recurrence


 
#include<bits/stdc++.h>
 
using namespace std;
 
#define ll unsigned long long
 
ll power(ll a,ll n)
{
 
    ll res=1;
 
    while(n>=1)
    {
 
        if(n&1)  res*=a;
 
        n>>=1;
 
        a*=a;
 
    }
 
    return res;
 
}
 
int main()
{
 
    int t;
    ll n;
    //ll a=3,b=35;
 
    //cout<<(ll)pow(a,b)-1<<endl;
    //cout<<power(a,b)-1<<endl;
 
    scanf("%d",&t);
 
    while(t--)
    {
 
        scanf("%llu",&n);
 
        printf("%llu\n",power(3ULL,n)-1);
 
    }
 
    return 0;
 
}
 
