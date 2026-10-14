class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen = INT_MAX;
        for(int i = 0; i < strs.size(); ++i)
            minlen = (strs[i].length() < minlen)?strs[i].length():minlen;
        bool flag = true;
        string ans;
        if(minlen == INT_MAX) return ans;
        for(int i = 0; i < minlen; ++i){
            char ch = '0';
            bool flag = true;
            for(int j = 0; j < strs.size(); ++j){
                if(ch == '0')
                    ch = strs[j][i];
                else if(strs[j][i] != ch){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            ans.push_back(ch);
        }
        return ans;
    } 
};
