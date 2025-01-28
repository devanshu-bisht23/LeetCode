class Solution {
public:

    void calculateCombinations(vector<int>& candidates, int target, int index, vector<int> &combi, int total, vector<vector<int>> &res){
        
        if(total == target){
            res.push_back(combi); //putting the combi once its total to target into res vector
            return;
        }

        if(total>target || index>= candidates.size()){
            return; 
        } 

        combi.push_back(candidates[index]); //filling to the left the first element
 
        calculateCombinations(candidates, target, index, combi, total + candidates[index], res); //left side
 
        combi.pop_back();

        calculateCombinations(candidates, target, index+1, combi, total, res); //right side

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;

        calculateCombinations(candidates, target, 0, combi, 0, res);

        return res;

    }
};