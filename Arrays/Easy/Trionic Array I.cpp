// Hint: Use three while loops
// Trial and error for edge cases

// Time Complexity:  O(n) due to single pass through the array
// Space Complexity:   O(1)

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(n==3 || nums[0]>nums[1])
            return false;
        
        int i=0, p=0, q=0;
        while(i<(n-1) && nums[i]<nums[i+1]){
            i++;
        }

        if(i<(n-1) && nums[i]>nums[i+1]){
            p=i;
            while(i<(n-1) && nums[i] > nums[i+1]){
                i++;
            }
        }

        if(i<(n-1) && nums[i]<nums[i+1]){
            q=i;
            while(i<(n-2) && nums[i]<nums[i+1]){
                i++;
            }
        }

        if((p && q) && (nums[i] < nums[i+1]))
            return true;

        return false;
        
    }
};