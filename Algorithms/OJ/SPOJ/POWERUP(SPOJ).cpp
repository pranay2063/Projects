// Application of FERMAT'S LITTLE THEOREM

// Fermat's Little theorem states that a^(p-1) = 1 (mod p) . Where p is prime .

// So if you have to calculate a^b mod ( p ) and b = k * (p-1) + m . Then you know a^b = (a^(p-1))^k * a^m . = 1^k * a^m = a^m

//  the wikipedia page for "fermat's" little theorem states that the relation a^(p-1) = 1 (mod p) would hold only in the case
//  when a is not divisible by prime  p

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned long long power2(unsigned long long a,unsigned long long n,unsigned long long MOD)
{

    unsigned long long res=1;

    //calculating (x^n)%MOD in log(n) time using iterative approach
    //Fast multiplication

    while(n>=1)
    {

        if(n&1)
        {

            res=(res*a)%MOD;

        }

        a=(a*a)%MOD;

        n=n/2;

    }

    return res;

}

int main()
{

    unsigned long long a,b,c,res1,res2;

    unsigned long long MOD=1000000007;

    //printf("%llu\n",((1000000006%MOD * 1000000006%MOD)%MOD*1000000006%MOD)%MOD);

    while(1)
    {
       scanf("%llu%llu%llu",&a,&b,&c);

       if(a==-1 && b==-1 && c==-1)
       break;

       //printf("%llu %llu\n",power(0,0,MOD-1),power(0,1,MOD));

       if(c==0)
       printf("%llu\n",a%MOD);

       else if(b==0)
            printf("1\n");

            else if(a%MOD==0)
                 printf("0\n");

                 // 0 0 1 -> 1 (not 0) because it is given that 0^0 is 1(assumption)

                 else printf("%llu\n",power2(a,power2(b,c,MOD-1),MOD));

    }

    // do not forget about the case 0 1000000006 1245

    // in this case ,answer should be 0 and not 1

    // it is because FERMAT'S THEOREM is applied when a and MOD are coprime (0 and 1000000007 are not coprimes as gcd is not 1)

    return 0;

}















