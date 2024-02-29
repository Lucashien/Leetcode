class Solution {
public:
    void print_q(deque<int>q){
        while (!q.empty()) {
            std::cout << q.front() << " ";
            q.pop_front();
        }
        cout <<endl;   
    }

    void print_v(vector<int>v){
        for(int i:v){
            cout << i <<" ";
        }
        cout << endl;
    }


    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> decreasing; // front 為最大值
        vector <int> res;
        
        // initial
        for(int i = 0;i<k;i++){
            while(!decreasing.empty()){
                if(nums[i] > decreasing.back())
                    decreasing.pop_back();
                else
                    break;
            }
            decreasing.push_back(nums[i]);
        }

        for(int left = 0,right = k;right<nums.size();right++){
            left = right - k;
            res.push_back(decreasing.front());
            if(decreasing.front() == nums[left]) {
                decreasing.pop_front();
            }

            // 判斷right是否為最大數
            while(!decreasing.empty()){
                if (nums[right] > decreasing.back()){
                    decreasing.pop_back();
                }
                else break;
            }
            
            decreasing.push_back(nums[right]);
        }
        
        res.push_back(decreasing.front());
        return res;

    }
};
