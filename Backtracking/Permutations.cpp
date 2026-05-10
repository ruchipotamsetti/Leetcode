// Time Complexity: O(n! * n) where n is the number of elements in the input array. 
// This is because there are n! permutations of the input array, and for each permutation, we need to copy the current permutation to the result vector, which takes O(n) time.
// Space Complexity: O(n) for the recursive call stack and the current permutation vector.  
class Solution {
public:
    vector<vector<int>>result;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>s;
        vector<int>curr;
        findPermutations(0, nums, curr, s);
        return result;   
    }

    void findPermutations(int i, vector<int>& nums, vector<int>& curr, unordered_set<int>& s){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }

        for(int j=i; j<nums.size(); j++){
            if(!s.count(nums[j])){
                curr.push_back(nums[j]);
                s.insert(nums[j]);

                findPermutations(0, nums, curr, s);
                s.erase(nums[j]);
                curr.pop_back();
            }
        }
    }
};