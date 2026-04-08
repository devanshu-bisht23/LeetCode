class Solution {
public:
    string longestPalindrome(string s) {
        
        string str = "";
        int len = 0;
        int n = s.length();

        for(int i=0; i<n; i++){
            
            int l = i;
            int r = i;

            while(l>=0 && r<n && s[l] == s[r]){
                if((r-l+1)>len){
                    str = s.substr(l,r-l+1);
                    len = r-l+1;
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;

            while(l>=0 && r<n && s[l] == s[r]){
                if((r-l+1)>len){
                    str = s.substr(l,r-l+1);
                    len = r-l+1;
                }
                l--;
                r++;
            }          

        }

        return str;

    }
};