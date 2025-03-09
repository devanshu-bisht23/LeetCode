class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size(); //length of colors array
        int l = 0; // first pointer (left)
        int output = 0; // what we will return at the end
        for(int r=1; r< n + k - 1; r++){

            if(colors[r%n]==colors[(r-1)%n]){ //it means the colors are not alternating // %n logic is for when loop starts
                l=r; // we slide the window
            }

            if(r-l+1 > k){ //if window becomes bigger than k
                l++;
            }

            if(r - l + 1 == k){ // if window is equals to k
                output++;
            }

        }
    return output;
    }
};