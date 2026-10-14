//we learn at each step in our life

//After not being able to solve an easy Q. on codeforces related to counting triangles,
//this is the time to solve sth which i always to do

//TRICOUNT-SPOJ


#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int main()
{

	int t;
	ull n;

	scanf("%d",&t);

	while(t--)
	{

		scanf("%llu",&n);

		ull ans=0;

		if(n&1)
		{

			//case when n is odd

			//summation of i*(i+1) for all i <=n - summation of (2*j-1)*j for all j <=(n/2+1)

			ull m=n/2+1;

			ans=n*(n+1)*(n+2)/3-m*(m+1)*(2*m+1)/3+m*(m+1)/2;

		}
		else	{

				//case when n is even

				//summation of i*(i+1)/2 for all i<=n + summation of (2*j-1)*j for j<=n/2 

				ull m=n/2;

				ans=n*(n+1)*(n+2)/6+m*(m+1)*(2*m+1)/3-m*(m+1)/2;

			}

		printf("%llu\n",ans);

	}

	return 0;

}





















