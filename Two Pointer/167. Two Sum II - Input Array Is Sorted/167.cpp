class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // input 的numbers是sort好的
        // 設定頭尾兩指針，若比目標小，low指針往後（變大）
        // 若比目標大，high指針往前（變小）
        int low = 0, high = numbers.size() - 1;

        while(low<high){
            int sum = numbers[low]+numbers[high];
            if(sum==target){
                return {low+1,high+1};
            }
            else if(sum>target){
                high--;
            }
            else if(sum<target){
                low++;
            }
        }
        return {0};
    }
};
