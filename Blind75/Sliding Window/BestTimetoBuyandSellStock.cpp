// Brute Force: TC: O(n^2) -> Will lead to TLE

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j]>prices[i]){
                    maxProfit = max(maxProfit, prices[j]-prices[i]);
                }
            }
        }
        return maxProfit;
    }
};

// My solution: TC: O(n), this works but can be optimized; here I continue even if the buying price is greater than the selling price which needs to be optimized, there is no check for it

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        int minBuy = prices[0];
        int i=1;
        while(i<n){
            maxProfit = max(maxProfit, prices[i]-minBuy);
            minBuy = min(minBuy, prices[i]);
            i++;
        }
        return maxProfit;
    }
};


// Solution 3: Sliding window, TC: O(n), here we update the l(left index) when we see that buying price is greater than the selling price, so only prices after the new l, can be a selling price

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        int l=0, r=1;
        while(r<n){
            if(prices[r]>prices[l]){
                maxProfit = max(maxProfit, prices[r]-prices[l]);
            }
            else{
                l=r; // check to change l, when l>r, l is the buying price
            }
            r++;
        }
        return maxProfit;
    }
};

