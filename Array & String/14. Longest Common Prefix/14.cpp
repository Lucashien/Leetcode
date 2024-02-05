class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // sort strs' element -> the 1st and the last element will be the most different element
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string fw = strs[0];
        string lw = strs[n-1];
        int wl = min(fw.size(),lw.size()); // word length
        string ans = "";
        // compare the alphabet
        for(int i = 0; i<wl;i++){
            if(fw[i]!=lw[i]){
                break;
            }
            ans+=fw[i];
        }
        return ans;
    }
};
