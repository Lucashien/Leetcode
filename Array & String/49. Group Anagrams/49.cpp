class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,int> mp;
        vector<vector<string>> ans;

        for (int i = 0; i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            // 判斷新字詞有無在mp內
            if(mp.find(temp)!=mp.end()){
                ans[mp[temp]].push_back(strs[i]);
            }
            else {
                mp[temp] = ans.size(); // new key to a new index
                ans.push_back({strs[i]}); // need to push a vector, so using {} to let strs[i] be a vector
            }
        }
        return ans;

    }
};
