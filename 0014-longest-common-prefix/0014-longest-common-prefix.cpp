class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";

        string ans = "";
        string str = strs[0];  

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            for (int j = 1; j < strs.size(); j++) {
               
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return ans; 
                }
            }

            ans += c;
        }

        return ans;
    }
};
