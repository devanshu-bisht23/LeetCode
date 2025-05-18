class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n = numCourses;
        vector<vector<int>> adj(n);

        vector<int> incoming(n,0);

        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            incoming[pre[0]]++;
        }
        
        queue<int> q;

        for(int i=0; i<n; i++){
            if(incoming[i] == 0){
                q.push(i);
            }
        }

        vector<int> res;

        while(!q.empty()){

            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto it: adj[node]){
                incoming[it]--;
                if(incoming[it] == 0) q.push(it);
            }

        }

    if (res.size() == numCourses) return res;
    
    return {};

    }
};