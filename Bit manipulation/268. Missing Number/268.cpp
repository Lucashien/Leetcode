class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 3 ^ 3 = 0
        // 0 ^ 3 = 3
        // 3 ^ 4 = nothing
        // missing number 會導致要搜的數跟size一樣大
        // 所以i對照組從1~n (ans = 0已算過)
        int ans = 0;
        for (int i = 1; i<= nums.size();i++){
            ans = ans ^ i;
            ans = ans ^ nums[i-1];
        }
        return ans;
    }
};
