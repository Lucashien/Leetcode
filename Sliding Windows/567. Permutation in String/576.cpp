class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector <int> mp1(26),mp2(26);
        
        for(char c:s1){
            mp1[c - 'a']++;
        }
        
        for(int i = 0;i<n2;i++){
            mp2[s2[i] - 'a']++;
            if(i>=n1){
                mp2[s2[i-n1] - 'a']--;
            }
            
            if(mp1==mp2) return true;
        }

        return false;
    }
};
