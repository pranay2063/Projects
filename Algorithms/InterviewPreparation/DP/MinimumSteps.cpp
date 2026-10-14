#include <iostream>
using namespace std;

const int MAX = 1000001;
int dp[MAX]  = {0};

void minSteps(){
	
	//At each step, we can divide N by 3, divide by 2, subtract 1
	//We need to find minimum steps to reach 1 from given N
	//Dynamic Programming
	
	dp[1] = 0;
	for(int i = 2; i < MAX; ++i){
		dp[i] = dp[i-1]+1;
		if(i%3 == 0)
			dp[i] = min(dp[i], dp[i/3]+1);
		if(i%2 == 0)
			dp[i] = min(dp[i], dp[i/2]+1);
	}
	
}

int main() {
	
	int testCases, N;
	cin>>testCases;
	
	minSteps();
	
	while(testCases--){
		cin>>N;
		cout<<"Minimum Steps ("<<N<<") : "<<dp[N]<<"."<<endl;
	}
	
	return 0;
}
