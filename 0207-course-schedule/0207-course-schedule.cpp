class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj_list(n);
        vector<int> indegree(n,0);

        for(auto it: pre){
            adj_list[it[1]].push_back(it[0]); 
            indegree[it[0]]++;
        }
 
        queue<int> q;

        for(int i=0; i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){

            int node = q.front();
            q.pop();
            count++;

            for(int it: adj_list[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }

        }

        if(count == n){
            return true;
        }else{
            return false;
        }
    }
};