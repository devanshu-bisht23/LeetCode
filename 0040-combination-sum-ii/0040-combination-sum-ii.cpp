class Solution {
public:

    void recursion(int ind, vector<int> &ans, vector<vector<int>> &res, vector<int>& c, int target){

        if(target == 0){
            res.push_back(ans);
            return;
        }

        for(int i=ind; i<c.size(); i++){ // start from 0
            
            if(i>ind && c[i]==c[i-1]) continue;

            if(c[i]>target) break;
            ans.push_back(c[i]);
            recursion(i+1,ans,res,c,target-c[i]);
            ans.pop_back();

        }

    }


    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        
        sort(c.begin(),c.end());
        vector<vector<int>> res;
        vector<int> ans;
        recursion(0,ans,res,c,target);

        return res;
    }
};