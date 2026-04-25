class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());

        while(!q.empty()){

            string word = q.front().first;
            int count = q.front().second;

            q.pop();

            for(int i=0; i<word.size(); i++){

                string target = word;

                for(int j='a'; j<='z'; j++){
                    target[i] = j;

                    if(st.find(target) != st.end()){
                        q.push({target,count+1});
                        st.erase(target);
                    }

                    if(q.front().first == endWord) return q.front().second;

                }

            }

        }

        return 0;

    }
};