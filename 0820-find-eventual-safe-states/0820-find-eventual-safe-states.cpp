class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> adj_rev(n);
        vector<int> indegree(n,0);
        queue<int> q;

        for(int i=0; i<graph.size(); i++){
            for(auto it:graph[i]){
                adj_rev[it].push_back(i);
                indegree[i]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it: adj_rev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};