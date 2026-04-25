class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;
    
    void dfs(string word, string beginWord, vector<string>& path){
        if(word == beginWord){
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(auto &p : parent[word]){
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while(!q.empty() && !found){
            int size = q.size();
            unordered_set<string> tempVisited;

            for(int i = 0; i < size; i++){
                string word = q.front();
                q.pop();

                string original = word;

                for(int j = 0; j < word.size(); j++){
                    char temp = word[j];

                    for(char c = 'a'; c <= 'z'; c++){
                        word[j] = c;

                        if(st.count(word)){
                            if(!visited.count(word)){
                                if(!tempVisited.count(word)){
                                    q.push(word);
                                    tempVisited.insert(word);
                                }
                                parent[word].push_back(original);
                            }

                            if(word == endWord) found = true;
                        }
                    }
                    word[j] = temp;
                }
            }

            for(auto &w : tempVisited){
                visited.insert(w);
            }
        }

        if(!found) return {};

        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);

        return ans;
    }
};