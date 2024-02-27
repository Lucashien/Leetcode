class Solution {
public:
    int characterReplacement(string s, int k) {
        // 可以選擇k個字母變成任意字母，return 最長相同字母
        int low = 0, high = 0;
        int maxf = 0,windows = 0,ans=0;

        // key , freq
        unordered_map <char,int> mp; 

        for( ;high < s.size();high++){
            mp[s[high]]++;
            windows = high - low + 1;
            maxf = max(maxf,mp[s[high]]);

            if(windows-  maxf <= k){
                ans = max(ans,windows);
            }
            else{
                mp[s[low]]--;
                low++;
            }
        }

        return ans;
    }
};
