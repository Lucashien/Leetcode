class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 任選三個相加為0 -> main for loop num = 任兩數字相加
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            int low = i + 1, high = n - 1;
            int target = -nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            while(low<high){
                int sum = nums[low] + nums[high];
                if(sum > target) high--;
                else if (sum<target) low ++;
                else {
                    ans.push_back({-target,nums[low],nums[high]});
                    low++;
                    high--;
                    
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
            }
        }

        return ans;
    }
};
