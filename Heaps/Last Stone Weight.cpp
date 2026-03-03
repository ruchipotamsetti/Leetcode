//1 Brute force(my approach):
//time complexity: O(n^2logn) for sorting the array in each iteration and 
// O(n) for erasing elements from the array, where n is the number of stones. 
// In the worst case, when all stones have different weights, this can be O(n^2 log n). 
// In the best case, when all stones have the same weight, this can be O(n log n) 
// for sorting the array once and O(1) for erasing elements from the array.
//space complexity: O(1) for using a constant amount of extra space to store temporary variables 
// and modify the input array in place. However, if we consider the space 
// used by the sorting algorithm, it can be O(n) in the worst case 
// due to the recursive stack space used by the sorting algorithm.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];

        while(stones.size()>=2){
            sort(stones.begin(), stones.end(), greater<int>());

            if(stones[0]==stones[1]){
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
            else{
                stones.push_back(stones[0]-stones[1]);
                stones.erase(stones.begin());
                stones.erase(stones.begin());
            }
        }

        if(stones.size()==0)
            return 0;
        return stones[0];
    }
};

//2 using binary search(need to review)

//3 Optimal approach using a max heap (priority queue):
//time complexity: O(n log n) for building the max heap and O(n log n) for processing the stones, 
// resulting in an overall time complexity of O(n log n).
//space complexity: O(n) for storing the stones in the max heap, 
// where n is the number of stones. In the worst case, 
// when all stones have different weights, this can be O(n). 
// In the best case, when all stones have the same weight, this can be O(1) 
// for storing a single stone in the max heap. 

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
            return stones[0];

        priority_queue<int>pq;

        for(auto i:stones){
            pq.push(i);
        }

        while(pq.size()>=2){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x!=y){
                pq.push(y-x);
            }
        }

        if(pq.size()==0)
            return 0;
        return pq.top();
    }
};

//4 using bucket sort(need to review)