class Solution {
public:
    int possibleStringCount(string word) {
        
        int count = 1;
        int i = word.size() - 1;
        while(i!=0){
            
            if(word[i] == word[i-1]){
                count++;
            }
            i--;
        }

        return count;

    }
};