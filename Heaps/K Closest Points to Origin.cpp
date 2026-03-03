//brute force:
//time complexity: O(n log n) for sorting the points based on their distances from the origin,
// where n is the number of points. The sorting step dominates the overall time complexity.
//space complexity: O(n) for storing the distances and the mapping of distances to points,
// where n is the number of points. In the worst case, when all points have different distances, 
// this can be O(n). In the best case, when all points have the same distance, 
// this can be O(1) for storing a single distance and its corresponding points.   
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<double, vector<vector<int>>>mp;
        vector<double>distances;

        for(auto i:points){
            double dist = sqrt((i[0]*i[0])+(i[1]*i[1]));
            mp[dist].push_back(i);
            distances.push_back(dist);
        }

        sort(distances.begin(), distances.end());
        vector<vector<int>> results;
        int i=0;
        while(i<k){
            vector<vector<int>>temp = mp[distances[i]];
            if(temp.size()>1){
                int j=0;
                while(i<k && j<temp.size()){
                    results.push_back(temp[j]);
                    i++;
                    j++;
                }
            }
            else{
                results.push_back(mp[distances[i]][0]);
                i++;
            }   
        }
        return results;
    }
};

//better written brute force approach:
//time complexity: O(n log n) for sorting the points based on their distances from the origin,
// where n is the number of points. The sorting step dominates the overall time complexity.
//space complexity: O(1) for storing a constant amount of additional space, 
// as the sorting is done in-place and we are not using any additional 
// data structures to store distances or points. 
// However, if we consider the space used by the sorting algorithm, it can be O(n) in the worst case 
// due to the recursive stack space used by the sorting algorithm.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        });

        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};

//using min heap:
//time complexity: O(n log n) for building the min heap and O(k log n) for extracting the k closest points,
// resulting in an overall time complexity of O(n log n) when k is small compared to n.
//space complexity: O(n) for storing the points in the min heap, where n is the number of points. 
// In the worst case, when all points have different distances, this can be O(n). 
// In the best case, when all points have the same distance, 
// this can be O(1) for storing a single point in the min heap.
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b){
            return (a[0]*a[0] + a[1]*a[1])>(b[0]*b[0]+b[1]*b[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>minHeap(comp);

        for(auto point: points){
            minHeap.push({point[0], point[1]});
        }

        vector<vector<int>>result;

        for(int i=0; i<k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};

//using max heap:
//time complexity: O(n log k) for building the max heap and O(k log k) for extracting the k closest points,
// resulting in an overall time complexity of O(n log k) when k is small compared to n.
//space complexity: O(k) for storing the k closest points in the max heap, 
// where k is the number of closest points we want to find. 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>pq;

        for(auto point:points){
            int dist = point[0]*point[0]+point[1]*point[1];
            pq.push({dist, {point[0], point[1]}});
            if(pq.size()>k)
                pq.pop();
        }

        vector<vector<int>>result;
        while(!pq.empty()){
            result.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return result;
    }
};

//quick select approach:(need to review)
//time complexity: O(n) on average, where n is the number of points. In the worst case, it can be O(n^2) if the pivot selection consistently results in unbalanced partitions.
//space complexity: O(1) for the in-place partitioning, but O(n) in the worst case due to the recursive stack space used by the quick select algorithm.