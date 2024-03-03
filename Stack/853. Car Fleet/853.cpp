class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // 後面車到終點花的時間 < 前面車到終點花的時間 -> 會塞車
        // 計算每台車到終點花的時間

        vector <pair<int,float>> time; // pair <time, idx>
        stack <float> st;
        for(int i = 0; i < position.size(); i++){
            time.push_back({position[i], (target - position[i])/(float)speed[i]});
        }
        sort(time.begin(),time.end());

        int n = time.size();
        st.push(time[n-1].second);
        for(int i = n-2;i>=0;i--){
            if(st.top() < time[i].second) {
                st.push(time[i].second);
            }
        }
        
    return st.size();
    }
};
