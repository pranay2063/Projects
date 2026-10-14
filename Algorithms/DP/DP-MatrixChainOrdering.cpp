#include<bits/stdc++.h>
using namespace std;

const int MAX = 405;
int dp[MAX][MAX],split[MAX][MAX];
vector<bool> computed(MAX,false);

void print(int i,int j)
{

    // A function to print optimal parenthesizations
    if(i!=j)
    {
        // Optimal Parenthesizations
        print(i,split[i][j]);
        print(split[i][j]+1,j);
        
        //string istr=computed[i] ? "->result " : " ";
        //string jstr=computed[j] ? "->result " : " ";

        cout<< "[" << i << "," << split[i][j] << "]" << " * " << "[" << (split[i][j]+1) << "," << j << "]" <<endl;
        //cout<<"A["<<i<<"]="<<"A["<< i << "]" << istr << "* A[" << j << "]" << jstr<<endl;

        computed[i] = true;
        computed[j] = true;
    }

}

void print2(int i,int j)
{

    // A function to print optimal parenthesizations
    // Optimal Parenthesizations
    if(i==j) cout<<"A["<<i<<"]";
    else {
              cout<<"(";
              print2(i,split[i][j]);
              print2(split[i][j]+1,j);
              cout<<")";
         }

}


int main()
{

    //https://en.wikipedia.org/wiki/Matrix_chain_multiplication
    int n;

    // there are n matrices
    // ith matrix  has dimension p[i-1] * p[i] for i = 1..n
    // thus p has length (n+1)

    scanf("%d",&n);
    int p[n+1];

    for(int i=0;i<=n;i++) scanf("%d",&p[i]);

    // Dynamic Programming
    // Complexity of the algorithm is O(n*n*n)

    // we take small intervals of length 2 to n and find the value of dp[i][j]
    // dp[i][j] stores the minimum number of operations in interval (i,j)
    // intervals of length 1 has no operations so that dp[i][i]=0

    // we start from small intervals and solution for bigger intervals are found from solutions of the former
    // bottom up approach

    // for each interval (i,j) , we find an index k in [i,j) such that dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j] is minimum
    // split[i][j] stores index k in [i,j)

    // this is not the fastest known algorithm for this purpose
    // Hu & Shing (1981) has O(nlogn) complexity

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=(n-len+1);i++)
        {
            int j=i+len-1;
            dp[i][j]=INT_MAX;

            for(int k=i;k<=(j-1);k++)
            {
                int temp=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<dp[i][j])
                {
                    dp[i][j]=temp;
                    split[i][j]=k;
                }
            }
        }
    }

    printf("%d",dp[1][n]);
    putchar('\n');
    putchar('\n');
    print2(1,n);  // Optimal Parenthesizations

    return 0;

}



























































