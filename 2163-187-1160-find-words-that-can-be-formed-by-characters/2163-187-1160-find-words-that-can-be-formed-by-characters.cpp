class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

       unordered_map<char,int> hashMap;
       int count = 0;
       for(int i = 0; i<chars.size(); i++){

            hashMap[chars[i]]++; //frequency stored of each char in chars

       }

        for(const auto& word : words){
            unordered_map<char,int> hashMap2 = hashMap;
            bool valid = true;
            for(const auto& ch : word){
                if(hashMap2[ch]>0){
                    hashMap2[ch]--;
                }else{
                    valid = false;
                    break;
                }
            }

            if(valid){
                count+= word.size();
            }
            }
    return count;
    }
};