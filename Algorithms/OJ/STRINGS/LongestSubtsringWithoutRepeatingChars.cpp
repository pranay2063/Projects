class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0) return 0;
        int ans = 1, cnt = 0;
        map<char,int> mp; //stores last occurence of a character
        for(int i = 0; i < s.length(); ++i){
            if(mp.find(s[i]) == mp.end()){
                ++cnt;
                mp[s[i]] = i;
            }
            else{
                ++cnt;
                int diff = i - mp[s[i]];
                if(diff <= cnt) cnt = diff;
                mp[s[i]] = i;
            }
            //cout<<cnt<<endl;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
}; 
