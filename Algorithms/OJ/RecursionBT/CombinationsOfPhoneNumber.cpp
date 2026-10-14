class Solution {
    
    vector<string> ans;
    
public:
    
    void recurse(string str, int idx, string tmp, vector<vector<char> > phone){    
    
        int sz;
        if(str[idx]-48-2 == 5 || str[idx]-48-2 == 7) sz = 4;
        else sz = 3;
        
        if(idx == str.length()-1){
            //Base case
            for(int i = 0; i < sz; ++i){
                string tmp2 = tmp;
                tmp2 += phone[str[idx]-48-2][i];
                ans.push_back(tmp2);
            }
            return ;
        }
        for(int i = 0; i < sz; ++i){
            string temp = tmp;
            temp.push_back(phone[str[idx]-48-2][i]);
            recurse(str, idx+1, temp, phone);   
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0) return ans;
        
        vector<vector<char> > phone;
        
        //Build map for key to characters
        int c = 96;
        for(int i = 2; i < 10; ++i){
            vector<char> ptemp;
            ptemp.push_back(++c);
            ptemp.push_back(++c);
            ptemp.push_back(++c);
            if(i == 7 || i == 9)
                ptemp.push_back(++c);
            phone.push_back(ptemp);
        }
    
        //call recursion on string for all possible combinations
        recurse(digits, 0, "", phone);
        return ans;
        
    }
};
