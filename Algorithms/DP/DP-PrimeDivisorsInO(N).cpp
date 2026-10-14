#include<bits/stdc++.h>
using namespace std;

#define ll int
const ll MAX=5000000;

ll a[MAX+5],sum_prime_powers[MAX+5];
//sum_prime_powers denotes sum of powers of prime factors of i at any index i

int main()
{

    //http://codeforces.com/blog/entry/18031?#comment-229101
    //http://codeforces.com/problemset/problem/546/D
    ll i,j; 

    for(i=2;i<=MAX;i++)
    {
        if(!a[i]) 
        {
            a[i]=i;
            if(1LL*i*i<=MAX) j=i*i;
            else continue;

            for(j=i*i;j<=MAX;j+=i)
            {
                a[j]=i;
                //a[i] stores the smallest divisor of  i
            }
        }
    }

    for(i=2;i<=MAX;i++)
    {
        //ll temp=i/a[i];
        sum_prime_powers[i]=1+sum_prime_powers[i/a[i]]; //Using DP , we can find number of divisors of all i in O(n)
    }

    //sum up the divisors till i
    for(i=2;i<=MAX;i++)
    sum_prime_powers[i]+=sum_prime_powers[i-1];

    ll t,s,b;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&s,&b);
        //cin>>s>>b;
        //cout<<d[s]<<" "<<d[b]<<endl;

        printf("%d\n",sum_prime_powers[s]-sum_prime_powers[b]);
        //cout<<d[s]-d[b]<<endl;
    }

    return 0;

}







