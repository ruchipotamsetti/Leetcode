
// Time Complexity: O(2^n) where n is the number of elements in the input array. 
// This is because for each element, we have two choices: include it in the subset or exclude it. 
// Therefore, the total number of subsets is 2^n.
// Space Complexity: O(2^n) for storing all the subsets in the results vector. 
// Additionally, the space complexity of the recursive call stack is O(n)
// in the worst case when all elements are included in the subset. 
// However, since we are storing all subsets, the overall space complexity is dominated by O(2^n).
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;

        findSubsets(0, candidates, target, result, curr, 0);

        return result;
    }

    void findSubsets(int i, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr, int sum){

        // base case: if we have reached the end of the candidates array, we return.
        if(i >= candidates.size()){ 
            return;
        }

        if(sum == target){
            result.push_back(curr);
            return;
        }
        if(sum > target)
            return;

        // make choice: include the current candidate and move to the next candidate (i) or exclude the current candidate and move to the next candidate (i+1)
        curr.push_back(candidates[i]);
        sum += candidates[i];
        // recurse: move to the next candidate (i) since we can reuse the same candidate
        findSubsets(i, candidates, target, result, curr, sum);
        // backtrack: remove the current candidate from the current combination and move to the next candidate (i+1)
        sum -= candidates[i];
        curr.pop_back();
        findSubsets(i+1, candidates, target, result, curr, sum);

    }
};