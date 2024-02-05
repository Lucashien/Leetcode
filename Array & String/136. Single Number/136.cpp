class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // using XOR to find unique element
        for(int i = 0;i<nums.size();i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};
