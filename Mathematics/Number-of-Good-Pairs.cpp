class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodPairs = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if (nums[i] == nums[j])
                    goodPairs++;
            }
        }
        return goodPairs;
    }
};
