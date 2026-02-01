// 1st Feb 2026

// Hints that helped me solve the problem::
// 1. No need to sort all the elements.
// 2. First element of the array will always be added in the the resulting sum. Why? Because it will always be part of the one of the subarrays.
// 3. Find out the two minimum elements from 1 to n, they will make your second and third subarray.


// Time Complexity:  O(n log n) due to sorting
// Space Complexity:   O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size() == 3)
            return nums[0]+nums[1]+nums[2];
        
        int minSum = nums[0];
        sort(nums.begin()+1, nums.end());

        minSum += nums[1]+nums[2];

        return minSum;
    }
};