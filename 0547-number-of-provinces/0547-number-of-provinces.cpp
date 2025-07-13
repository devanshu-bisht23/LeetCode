class Solution {
public:

    void dfs(int start, vector<vector<int>> &adj_list,vector<int> &visited){

        visited[start] = 1;

        for(auto it: adj_list[start]){
            if(visited[it] != 1){
                dfs(it, adj_list, visited);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>> adj_list(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        vector<int> visited(n+1, 0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i] != 1){
                count++;
                dfs(i, adj_list,visited);
            }
        }

return count;

    }
};