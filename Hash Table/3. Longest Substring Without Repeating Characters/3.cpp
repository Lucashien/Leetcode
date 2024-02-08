class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // using "set"" to judge the substr is repeated or not
        int maxlength = 0;
        unordered_set <char> set;

        int rp = 0, lp = 0; // right/left pointer

        for(int rp = 0; rp < s.size(); rp++){
            
            // !repeat
            if(set.count(s[rp])==0) {
                set.insert(s[rp]);
                maxlength = max(maxlength,rp-lp+1);
            }
            // repeat
            // 1. erase the char that pointed by lp
            // 2. lp++
            // 3. insert char that pointed by rp
            else {
                while(set.count(s[rp]) > 0){
                    set.erase(s[lp]);
                    lp++;
                }
                set.insert(s[rp]);
            }

        }
        return maxlength;
    }
};
