#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end)/2;

        while (start <= end){
            mid = (start+end)/2;
            
            // target比mid大，代表從start到mid都沒有target，所以把start更新成mid+1
            if (target > nums[mid]){
                start = mid + 1;
            }
            // target比mid小，代表從mid到end都沒有target，所以把end更新成mid-1
            else if (target < nums[mid]){
                end = mid -1;
            }
            // mid==target
            else{
                return mid;
            } 
        }
        return start;
    }
};