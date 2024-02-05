class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;
        for(int i = 0; i<s.length();i++){
            char c = s[i];
            char next_c = s[i+1];
            if(m[c]<m[next_c]){

                ans -= m[c];
            }
            else{
                ans += m[c];
            }
        }
        return ans;
    }
};
