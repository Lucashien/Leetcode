class Solution {
public:
    bool isPalindrome(string s) {
        // setting 2 pointer: left and right
        // judge left and right if the same
        if(s.empty()) return true;
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            char left_char = tolower(s[left]);
            char right_char = tolower(s[right]);
            if(!isdigit(left_char) && !isalpha(left_char)){
                left++;
                continue;
            }
            if(!isdigit(right_char) && !isalpha(right_char)){
                right--;
                continue;
            }
            
            if(left_char!=right_char){
                return false;
            }
            // char相同
            else{
                left++;
                right--;
            }
        }
        return true;

    }
};
