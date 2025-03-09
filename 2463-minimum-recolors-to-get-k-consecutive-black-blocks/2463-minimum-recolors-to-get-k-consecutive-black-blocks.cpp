class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=k-1;
        int minimum=101, sum;

        while(j<blocks.size()){
            sum = 0;
            for (int x = i; x <= j; x++) {
                if (blocks[x] == 'W') {
                    sum++;
                }
            }
            minimum = min(minimum, sum);
            i++,j++;
        }
    return minimum;
    }
};