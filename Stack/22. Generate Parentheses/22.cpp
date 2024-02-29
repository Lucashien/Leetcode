class Solution {
public:
    vector <string> res;

    void generate(int left, int right, int n, string s){
        if(left == right && right == n){
            res.push_back(s);
            return;
        }

        // 若open的數量沒達到n，可以增加open
        // 若close不夠，可進行close
        if(left < n) generate(left + 1, right, n, s + '(');
        if(left > right) generate(left, right + 1, n, s + ')');
    }

    vector<string> generateParenthesis(int n) {
        generate(0,0,n,"");
        return res;
    }
};
