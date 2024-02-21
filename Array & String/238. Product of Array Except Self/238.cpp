class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 分成左右容器 
        // forward backward vector
        int n = nums.size();
        vector<int> fv(n);
        vector<int> bv(n);
        vector<int> ans(n); 


        fv[0] = 1;
        bv[n-1] = 1;
        for(int i = 1; i<n;i++){
            fv[i] = fv[i-1] * nums[i-1];
        }

        for(int i = n-2; i>=0;i--){
            bv[i] = bv[i+1] * nums[i+1];
        }

        for(int i = 0;i<n;i++){
            ans[i] = fv[i] * bv[i];
        }

        return ans;
        
    }
};
