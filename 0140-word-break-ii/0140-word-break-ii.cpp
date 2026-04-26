class Solution {
public:

    unordered_map<string, vector<string>> dp;
    vector<string> f(string s, vector<string>& wordDict){
        
        if(dp.count(s)) return dp[s];
        vector<string> ans;

        if(s.empty()){
            ans.push_back(""); // cuz hame ans return krna hai valid word banane ke lie
            return ans;
        }

        for(auto &w: wordDict){

            int size = w.size();
            if(s.substr(0,size) == w){

                vector<string> callBackString = f(s.substr(size),wordDict); // vapis aate time

                for(auto &c : callBackString){
                    ans.push_back(w + (c.empty()?"" : " ") + c); // concat callbacked string with valid split
                }

            }

        }

        return dp[s] = ans;    
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        return f(s,wordDict);

    }
};