class Solution {
public:


    void DFS(int start, vector<int> adj_list[], vector<int> &visited){  

            visited[start] = 1; 

            for(auto it: adj_list[start]){
                if(visited[it] != 1){
                    DFS(it, adj_list, visited);
                }
            }
    }

    int findCircleNum(vector<vector<int>>& isConnected) { 

        int n = isConnected.size();

        vector<int> adj_list[n];

        vector<int> visited(n+1, 0);

        for(int i = 0; i<n; i++){
            for(int j =0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(visited[i] != 1){
                count++;
                DFS(i, adj_list, visited);
            }
        }

        return count;

    }
};