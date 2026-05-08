// Time Complexity: O(2^n) where n is the number of elements in the input array. 
// This is because for each element, we have two choices: include it in the subset or exclude it. 
// Therefore, the total number of subsets is 2^n.
// Space Complexity: O(2^n) for storing all the subsets in the results vector. 
// Additionally, the space complexity of the recursive call stack is O(n) 
// in the worst case when all elements are included in the subset. 
// However, since we are storing all subsets, the overall space complexity is dominated by O(2^n).

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>results;
        vector<int>current;
        find_subsets(0, nums, results, current);

        return results;
    }

    void find_subsets(int i, vector<int>& nums, vector<vector<int>>& results, vector<int>& current){

        if(i==nums.size()){
            results.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        find_subsets(i+1, nums, results, current);

        current.pop_back();
        find_subsets(i+1, nums, results, current);

    }
};