class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> mp;
        priority_queue <pair<int,int>> q;
        vector <int> ans;

        // mp[num] = freq
        for (int num:nums){
            mp[num]++;
        }

        // push進priority_queue後，他會依照freq大小進行sort
        for (auto it : mp){
            int freq = it.second;
            int num = it.first;
            q.push({freq, num});
        }

        int n = nums.size();
        for (int i = 0; i<k; i++){
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};
