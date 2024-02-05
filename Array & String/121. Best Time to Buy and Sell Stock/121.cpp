class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int pf = 0; // profit
        int max_pf = 0;
        for(int i = 0; i< prices.size();i++){
            if(prices[i]<min){
                min = prices[i];
            }

            else if(prices[i]>min){
                pf = prices[i] - min;
            }

            if (pf>max_pf){
                max_pf = pf;
            }
        }
        return max_pf;

    }
};
