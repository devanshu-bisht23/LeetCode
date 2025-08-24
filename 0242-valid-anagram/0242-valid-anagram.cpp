class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;
        
        vector<int> alpha(26,0);

        for(int i=0; i<s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            
            alpha[c1 - 'a']++;
            alpha[c2 - 'a']--;

        }

        for(int i: alpha){
            if(i!=0){
                return false;
            }
        }

        return true;
        
    }
};