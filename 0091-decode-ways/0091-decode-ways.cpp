class Solution {
public:

    bool foundInHash(string str, vector<int> &hash){

        if(str.empty()) return false;
        if(str[0] == '0') return false;

        int num = stoi(str);

        for(int i = 1; i <= 26; i++){

            if(num == i){
                return true;
            }

        }

        return false;
    }

    int f(int ind, string s, int n, vector<int> &hash, string str, vector<int> &dp){

        if(ind == n) return 1;

        if(dp[ind] != -1) return dp[ind];

        int ans = 0;
        str = "";

        for(int i = ind; i < n && i < ind + 2; i++){

            str += s[i];

            if(foundInHash(str, hash)){
                ans += f(i + 1, s, n, hash, str, dp);
            }

        }

        return dp[ind] = ans;

    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> hash(27);

        for(int i = 1; i <= 26; i++){
            hash[i] = 'A' + (i - 1);
        }

        vector<int> dp(n, -1);

        string str = "";

        return f(0, s, n, hash, str, dp);

    }
};