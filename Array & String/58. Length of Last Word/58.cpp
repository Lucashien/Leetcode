class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size(), count = 0;
        bool flag = false;
        for(int i = size-1;i>=0;i--){
            if(s[i]!=' '){
                flag = true;
                count++;
            }
            else if(flag && s[i]==' '){
                break;
            }
        }
        return count;
    }
};
