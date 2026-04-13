class Solution {
public:
    string countAndSay(int n) {
        
        string curr = "1";
        
        for(int i = 2; i <= n; i++){
            
            string next = "";
            int count = 1;
            
            for(int j = 1; j < curr.length(); j++){
                
                if(curr[j] == curr[j-1]){
                    count++;
                } else {
                    next += to_string(count);
                    next += curr[j-1];
                    count = 1;
                }
            }

            next += to_string(count);
            next += curr.back();
            
            curr = next;
        }
        
        return curr;
    }
};


// class Solution {
// public:
//     string countAndSay(int n) {

//         string finalres = "";

//         if(n == 1) return "1";

//         for(int i=2; i<=n; i++){

//             int counter = 1; int tempIdx = 0;
//             string res = "";
//             string str = "11";

//             for(int j=1; j<res.length(); j++){
//                 if(str[j-1] == str[j]){
//                     counter++;
//                 }else{
//                     res[tempIdx] = counter;
//                     res[tempIdx+1] = str[tempIdx];
//                     tempIdx += 2;
//                     counter = 1;
//                 }
                
//             finalres = res;

//         }
        
//     return finalres;

//     }
// };