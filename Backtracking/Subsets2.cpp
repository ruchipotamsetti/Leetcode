// Time Complexity: O(n^2*2^n) where n is the number of elements in the input array. 
// This is because there are 2^n subsets of the input array, and for each subset,
// we need to copy the current subset to the result set, which takes O(n^2) time.  
// Space Complexity: O(n*2^n) for storing all the subsets in the result set. 
// Additionally, the space complexity of the recursive call stack is O(n) for the subset vector.
class Solution {
public:
    set<vector<int>>result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>subset;
        findSubsets(0, nums, subset);

        return vector<vector<int>>(result.begin(), result.end());
    }

    void findSubsets(int i, vector<int>& nums, vector<int>& subset){

        if(i>=nums.size()){
            result.insert(subset);
            return;
        }

        subset.push_back(nums[i]);
        findSubsets(i+1, nums, subset);
        subset.pop_back();
        findSubsets(i+1, nums, subset);

    }
};