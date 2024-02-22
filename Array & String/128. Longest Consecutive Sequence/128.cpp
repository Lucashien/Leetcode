class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 用set排序，確保沒有重複
        unordered_set <int> set (nums.begin(),nums.end());
        int ans = 0;
        for(int val: nums){
            if(set.count(val)){
                int pre = val - 1;
                int next = val + 1;
                set.erase(val);
                while(set.count(pre)) set.erase(pre--);
                while(set.count(next)) set.erase(next++);
                ans = max(ans,next - pre - 1);
            }
            else{
                continue;
            }

        }
        return ans;
    }
};
