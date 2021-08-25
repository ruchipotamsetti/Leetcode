/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1])
                return true;
            else
                i++;
        }
        return false;
    }
    
};
