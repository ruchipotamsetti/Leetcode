//My Solution:
//Time Complexity: O(nlogn) due to sorting
//Space Complexity: O(logn) This is the auxiliary space used by the sorting algorithm's recursion stack.

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n==1){
            return cost[0];
        }
        if(n==2){
            return cost[0]+cost[1];
        }

        sort(cost.begin(), cost.end());

        int minCost = 0;
        int i=n-1;
        while(i>=0){
            if(i>=1)
                minCost += cost[i]+cost[i-1];
            else
                minCost += cost[i];
            i-=3;
        }
        return minCost;
    }
};

//Optimal Solution:
//Time Complexity: O(nlogn) due to sorting
//Space Complexity: O(logn) This is the auxiliary space used by the sorting algorithm's recursion stack.

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<>());

        int minCost = 0;
        for(int i=0;i<cost.size(); i++){
            if(i%3 != 2)
                minCost += cost[i];
        }
        return minCost;
    }
};