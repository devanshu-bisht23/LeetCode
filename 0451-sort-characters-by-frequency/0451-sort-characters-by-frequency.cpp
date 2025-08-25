class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> hashMap;

        for(int i=0; i<s.size(); i++){
            hashMap[s[i]]++;
        }

        priority_queue<pair<int,char>> pq; 

        for(auto c: hashMap){

            int f = c.second;
            char ch = c.first;
            pq.push({f, ch});
        }

        string ans;

        while(!pq.empty()){

            int f = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            for(int i=0; i<f; i++){

                ans.push_back(ch);

            }


        }


    return ans;

    }
};