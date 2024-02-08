class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector <string> ans = {""};
        
        for (auto key : digits){ // go around the digits. key = '1' or '2'...
            vector <string> temp;
            string pair = mapping[key - '0']; // pair = "abc" or "def"...
            
            // using double loop and 2 container
            // a + "", b + "", c + "" -> ans = "a", "b", "c"
            // ans = "a", "b", "c"
            // tmep = ad, ae, af, bd, be, bf, cd, ce, cf -> ans = temp
            //        |1st loop | 2nd loop  | 3rd loop  |
            for (auto pair_c : pair){ 
                for(auto c: ans){
                    temp.push_back(c + pair_c);
                }
            }
            ans.clear();
            ans = temp;
        }
        return ans;
    }
};
