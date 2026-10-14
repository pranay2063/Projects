class Solution {
public:
    string longestPalindrome(string s) {
        
        int dp[1001][1001] = {0};
        for(int i = 0; i < s.length(); ++i) dp[i][i] = 1;
        //check if substrings of different lengths are palindrome or not
        //Apply dynamic programming by starting from smaller lengths to higher lengths 
        for(int i = 2; i <= s.length(); ++i){
            for(int j = 0; j+i-1 < s.length(); ++j){
                if(i == 2){
                    if(j+1 < s.length() && s[j] == s[j+1]){
                        dp[j][j+1] = 1;
                    }    
                }
                else{
                    if(j+i-1 < s.length() && s[j] == s[j+i-1]){
                        if(dp[j+1][j+i-2] == 1)
                            dp[j][j+i-1] = 1;
                    }
                }
            }
        }
        
        //Extract the palindromic substring of maximum length
        int start = 0, end = 0;
        int mxlen = 0;
        for(int i = 0; i < s.length(); ++i)
            for(int j = i+1; j < s.length(); ++j){
                if(dp[i][j] == 1){
                    if(j-i+1 > mxlen){
                        mxlen = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        
        return s.substr(start,end-start+1); 
        //Time : O(N^2)
        //Space : O(N^2)
    
    }
};
