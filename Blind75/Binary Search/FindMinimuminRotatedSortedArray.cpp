// Brute force: TC:O(n), but we want the algorithm to in O(log n)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElement = INT_MAX;

        for(int n: nums){
            minElement = min(minElement, n);
        }

        return minElement;
    }
};

// Binary search -> TC:O(logn)(Need to revise solution)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElement = INT_MAX;
        int n = nums.size();
        int l=0, r= n-1;

        while(l<=r){
            if(nums[l]<nums[r]){
                minElement = min(minElement, nums[l]);
                break;
            }
            int m = l+ (r-l)/2;
            minElement = min(minElement, nums[m]);
            if(nums[m]<nums[r]){
                r = m-1;
            }
            else{
                l=m+1;
            }
        }

        return minElement;
    }
};