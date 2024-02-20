class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // 先判斷是否可分類
        if (nums.size()%k!=0) return false;
        
        map <int,int> counter;

        for (int num:nums){
            counter[num]++;
        }

        while(counter.size()>0){
            // 從map中idx最小的數開始
            int start = counter.begin()->first;
            for(int i = start;i<start+k;i++){
                
                // 若需要的數沒有在map中，即return false (因為每個數都要用到)
                if(!counter.count(i)){
                    return false;
                }

                counter[i]--;

                // 若freq用完了，即刪除該key
                if(counter[i]==0){
                    counter.erase(i);
                }
            }
        }
        
        return true;
    }
};
