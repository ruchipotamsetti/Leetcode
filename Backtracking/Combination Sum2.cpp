// Time Complexity: O(2^n) where n is the number of elements in the input array. 
// This is because for each element, we have two choices: include it in the subset or
// exclude it. Therefore, the total number of subsets is 2^n.
// Space Complexity: O(2^n) for storing all the subsets in the results vector. 
// Additionally, the space complexity of the recursive call stack is O(n)  

class Solution {
public:
    vector<vector<int>>result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        findUnique(0, candidates, target, curr, 0);
        return result;
    }

    void findUnique(int i, vector<int>& candidates, int target, vector<int>& curr, int sum){
        if(sum==target){
            result.push_back(curr);
            return;
        }
        int prev=0;
        for(int j=i; j<candidates.size(); j++){
            if(prev==candidates[j])
                continue;
            if(sum+candidates[j]>target)
                return;
            curr.push_back(candidates[j]);
            findUnique(j+1, candidates, target, curr, sum+candidates[j]);
            prev=candidates[j];
            curr.pop_back();
        }
    }
};