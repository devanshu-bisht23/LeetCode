class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res; // Key: sorted word, Value: list of anagrams normally

        for (const auto& s : strs) {
            string key = s;  
            sort(key.begin(), key.end()); // Sort the word to get a common key for anagrams
            res[key].push_back(s); // The key is sorted for each ord but s, s is in its true form
        }

        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};
