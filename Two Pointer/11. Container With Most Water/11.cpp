class Solution {
public:
    int maxArea(vector<int>& height) {
        // 取兩指針的min*兩指針距離最大值
        
        int n = height.size();
        int low = 0, high = n - 1;
        int maxArea = 0;
        while(low < high){

            int h = min(height[low],height[high]);
            int currentArea = h*(high - low);
            maxArea = max(maxArea,currentArea);
            if (height[low]<=height[high]) low++;
            else if (height[low] > height[high]) high--;
        }
        return maxArea;
    }
};
