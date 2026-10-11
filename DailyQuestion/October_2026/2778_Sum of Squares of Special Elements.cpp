//My solution:
//Time Complexity: O(n) where n is the size of the input vector nums.
//We iterate through the vector once, performing constant time operations for each element. 
//Space Complexity: O(1) as we are using a constant amount of extra space for variables and 
// not using any additional data structures that scale with input size.    

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i=0;i<n;i++){
            int index = i+1;
            if(n%index == 0){
                result += (nums[i]*nums[i]);
            }
        }

        return result;
    }
};