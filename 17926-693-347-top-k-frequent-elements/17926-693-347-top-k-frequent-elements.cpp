class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        unordered_map<int,int> count; // empty hashmap 

        for(int num : nums){
            count[num]++; // key and value for hashmap, key is num and value is freq
        }    

        vector<pair<int,int>> arr;

        for(const auto& p: count){ // took a refrence of each key, value pair
            arr.push_back({p.second, p.first}); // then put the value first then key in a pair
        }

        sort(arr.rbegin(),arr.rend()); // we sort in descending order our pair 

        vector<int> res;

        for(int i=0; i<k; i++){ // till k cuz we want to only store top k frequency
            res.push_back(arr[i].second); // we only storing 2nd element which is our key
        }

        return res; // return those top k freq
    }
};