//my solution using min heap:
//time complexity: O(n log k) for iterating through the array and 
// maintaining the min heap of size k, where n is the number of 
// elements in the input array and k is the size of the heap. 
// In the worst case, when n is large and k is small, this can be O(n log k). 
// In the best case, when n is small and k is large, this can be O(log k) 
// for each insertion into the heap.
//space complexity: O(k) for storing the k largest elements in the min heap, 
// where k is the size of the heap. In the worst case, when k is large, this can be O(k). 
// In the best case, when k is small, this can be O(1) for storing a single element in the heap.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;

        for(auto num: nums){
            minHeap.push(num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        return minHeap.top();
    }

};

//brute force approach using sorting:
//time complexity: O(n log n) for sorting the array, 
// where n is the number of elements in the input array. 
// In the worst case, when n is large, this can be O(n log n). 
// In the best case, when n is small, this can be O(n log n) as well, 
// since sorting is required regardless of the input size.
//space complexity: O(1) for sorting the array in place, or O(n) if we consider the space used by the sorting algorithm.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

//Quick select algorithm:(need to review)
