class Solution {
public:

    bool canMake(int start, vector<int>& gas, vector<int>& cost){

        int end = start;

        int i = start;
        int tank = 0;
        int n = gas.size();
        int count = 0;

        while(count<n){

            int idx = i%n;
            tank += gas[idx];
            if(tank < cost[idx]) return false;

            tank -= cost[idx];

            i++;
            count++;

        }

    return true;

    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        if(n == 1 && gas[0] >= cost[0]) return 0;

        for(int i=0; i<n; i++){

            if(gas[i] > cost[i]){
                int start = i;
                if(canMake(start,gas,cost)){
                    return start;
                }
            }

        }
        return -1;
    }
};