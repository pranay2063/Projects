//Fibonacci Encoding encodes an integer into binary number using Fibonacci representation of the number

//The idea was first proposed by Zeckendorf and the theorem is called Zeckendorf's theorem
//The interesting point is that every positive number can be represented uniquely as a sum of distinct non-neighbouring Fibonacci numbers

//We take Fibonacci numbers as 1,2,3,5,...
//Using induction , it can be proved that unique representation is because of the distinct use of non-neighbouring Fibonacci numbers  

#include<string>
#include<iostream>

using namespace std;

#define ll long long

const int MAX = 101;
ll fib[MAX];
int sz; //size of Fibonacci array

void fibo()
{

	  fib[0]=1;
	  fib[1]=1;

	  int i;

	  for(i=2;i<88;i++)
	  fib[i]=fib[i-1]+fib[i-2];

	  sz = i-1;

}

int bsearch(ll n)
{

	  int res=0,start=1,end=sz;

	  while(start<=end)
	  {

		    int mid=(start+end)/2;

		    if(fib[mid] == n)
		    {

			      res=mid;
			      break;

		    }

		    else if(fib[mid]<n)
		    {

			      if(mid>res) res=mid;
			      start=mid+1;
		
		    }
		    else end=mid-1;

	  }

	  return res;

}

void codeword(ll n)
{

	  fibo();

	  //At each step , find the largest Fibonacci <= n
	  int ans[sz+1] = {0};
	  int last = -1;

	  while(n)
	  {

		  int idx = bsearch(n);
		  if(last == -1) last = idx;
		  ans[idx] = 1;
		  n = n - fib[idx];

	  }	

	  for(int i=1;i<=last;i++) cout<<ans[i];
	  cout<<"1"<<endl;

}

int main()
{

	  int t; //testcases
	  ll n;

	  cin>>t;

	  while(t--)
	  {

		    cin>>n; //number to be encoded (n <= 10^18)

		    codeword(n);

	  }

	  return 0;

}
