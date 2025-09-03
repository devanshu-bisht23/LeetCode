class Solution {
public:

    bool isPalin(string s, int start, int end){

        for(int i=start, j=end; i<=j; i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }

        return true;

    }

    void recursion(int ind, vector<vector<string>> &res, vector<string> &ans, string s){


        if(ind == s.size()){
            res.push_back(ans);
            return;
        }


        for(int i=ind; i<s.size(); i++){ 
            if(isPalin(s,ind,i)){

                ans.push_back(s.substr(ind, i - ind + 1));
                recursion(i+1, res,ans, s);
                ans.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> res;
        vector<string> ans;

        recursion(0,res,ans,s);

        return res;  

    }
};