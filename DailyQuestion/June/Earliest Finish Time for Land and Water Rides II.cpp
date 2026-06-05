//My solution: Traverse through different loops for both combinations. Don't continue if the first ride time is greater than the minimum time calculated so far. 
// Calculate the total time for both combinations and update the minimum time accordingly.
// Time Complexity: O(n*m) where n is the number of land rides and m is the number of water rides.
// We have two nested loops, the outer loop iterates through the land rides and the inner loop iterates through the water rides.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the minTime variable.
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n =  landStartTime.size();
        int m = waterStartTime.size();
        int earliestTime=INT_MAX;
        

        int landTime = INT_MAX;
        int i=0;
        while(i<n){
            if(landTime > landStartTime[i]+landDuration[i]){
                landTime = landStartTime[i]+landDuration[i];
                int j=0;
                while(j<m){
                    int totalTime = max(landTime, waterStartTime[j]) + waterDuration[j];
                    earliestTime =  min(earliestTime, totalTime);
                    j++;
                }
            }
            i++;
        }

        int waterTime = INT_MAX;
        i=0;
        while(i<m){
            if(waterTime > waterStartTime[i]+waterDuration[i]){
                waterTime = waterStartTime[i]+waterDuration[i];
                int j=0;
                while(j<n){
                    int totalTime = max(waterTime, landStartTime[j]) + landDuration[j];
                    earliestTime =  min(earliestTime, totalTime);
                    j++;
                }
            }
            i++;

        }
        return earliestTime;
    }
};

// Optimized Solution: Traverse using single loops for land and water rides to find the minimum finish times.
// Time Complexity: O(n+m) where n is the number of land rides and m is the number of water rides.
// We have two separate loops, one iterating through the land rides and the other iterating through the water rides.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the minTime variable.

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n =  landStartTime.size();
        int m = waterStartTime.size();
        int earliestTime=INT_MAX;
        int l=INT_MAX, w = INT_MAX, minLand=INT_MAX, minWater = INT_MAX;

        for(int i=0; i<n; i++){
            l = min(l, landStartTime[i]+landDuration[i]);
        }

        for(int i=0;i<m;i++){
            w = min(w, waterStartTime[i]+waterDuration[i]);
            minLand = min(minLand, max(l, waterStartTime[i])+waterDuration[i]);
        }

        for(int i=0;i<n; i++){
            minWater = min(minWater, max(w, landStartTime[i])+landDuration[i]);
        }

        return min(minLand, minWater);

        int landTime = INT_MAX;
        int i=0;
        while(i<n){
            if(landTime > landStartTime[i]+landDuration[i]){
                landTime = landStartTime[i]+landDuration[i];
                int j=0;
                while(j<m){
                    int totalTime = max(landTime, waterStartTime[j]) + waterDuration[j];
                    earliestTime =  min(earliestTime, totalTime);
                    j++;
                }
            }
            i++;
        }

        int waterTime = INT_MAX;
        i=0;
        while(i<m){
            if(waterTime > waterStartTime[i]+waterDuration[i]){
                waterTime = waterStartTime[i]+waterDuration[i];
                int j=0;
                while(j<n){
                    int totalTime = max(waterTime, landStartTime[j]) + landDuration[j];
                    earliestTime =  min(earliestTime, totalTime);
                    j++;
                }
            }
            i++;

        }
        return earliestTime;
    }
};