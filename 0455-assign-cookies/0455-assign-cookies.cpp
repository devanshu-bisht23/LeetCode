class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.empty()) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int i = 0, j = 0;

        while(i<g.size()){

            if(g[i] == s[j]){
                ans++;
                j++;
            }

            i++;

        }

        return ans;
    }
};