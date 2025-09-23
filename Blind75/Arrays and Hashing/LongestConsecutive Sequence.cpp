// Brute Force:



// Sorting:


//Optimized Solution:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        unordered_set<int>s;
        for(int i: nums){
            s.insert(i);
        }

        int longestSequence = 0, currentSequence;
        for(int i: s){
            currentSequence = 1;
            if(!s.count(i-1)){
                int j = i+1;
                while(s.count(j)){
                    j++;
                    currentSequence++;
                }
            }
            longestSequence = max(longestSequence, currentSequence);
        }

        return longestSequence;
    }
};