class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic stack ->　用stack去紀錄陣列遞減性
        // stack 內用 pair <val, idx>
        stack <pair<int,int>> s;
        int n = temperatures.size();
        vector <int> ans(n,0);

        for(int i = 0; i<n; i++){
            while(!s.empty()&&s.top().first<temperatures[i]){
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return ans;

    }
};
