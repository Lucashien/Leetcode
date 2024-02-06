class Solution {
public:
    int strStr(string haystack, string needle) {
        int nl = needle.size();
        for(int i = 0;i<haystack.size();i++) {
            if(haystack.substr(i,nl)==needle){
                return i;
            }
        }
        return -1;
    }
};
