/*for loop way (BFS)*/
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


/*Recursive way (DFS)*/
class Solution {
public:
    unordered_map <int, string> mapping;
    string ans = "";
    // component: 
    void solve(int idx,string& digits,vector<string>& final_ans ){

        if(idx>=digits.size()){
            final_ans.push_back(ans);
            return;
        }

        int num = digits[idx] - '0'; // 數字鍵
        string str = mapping[num];
        int size = str.size(); // 有幾個字母
        
        for(int i = 0;i<size;i++){
            ans +=str[i];
            solve(idx+1,digits,final_ans);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        mapping[2]=  {"abc"};
        mapping[3]=  {"def"};
        mapping[4]=  {"ghi"};
        mapping[5]=  {"jkl"};
        mapping[6]=  {"mno"};
        mapping[7]=  {"pqrs"};
        mapping[8]=  {"tuv"};
        mapping[9]=  {"wxyz"};

        vector<string> final_ans;
        if(digits.size()==0){
            return final_ans;
        }

        solve(0,digits,final_ans);
        return final_ans;

    }
};
