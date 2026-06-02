//My solution: Traverse through different loops for both combinations and calculate the total time for both combinations and update the minimum time accordingly.
// Time Complexity: O(n*m) where n is the number of land rides and m is the number of water rides.
// We have two nested loops, the outer loop iterates through the land rides and the inner loop iterates through the water rides.
// Space Complexity: O(1) as we are using only a constant amount of extra spacee for the minTime variable.  

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int landTime = landStartTime[i]+landDuration[i];
                int totalTime;
                if(waterStartTime[j]<=landTime){
                    totalTime = landTime + waterDuration[j];
                }
                else{
                    // int totalTime  = landTime +  waterStartTime[j] - landTime + waterDuration[j];
                    totalTime =  waterStartTime[j] + waterDuration[j]; 
                }
                if(totalTime<minTime)
                        minTime = totalTime;
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int waterTime = waterStartTime[i]+waterDuration[i];
                int totalTime;
                if(landStartTime[j]<=waterTime){
                    totalTime = waterTime + landDuration[j];
                    
                }
                else{
                    // int totalTime  = waterTime +  landStartTime[j] - waterTime + landDuration[j];
                    totalTime =  landStartTime[j] + landDuration[j];
                }
                if(totalTime<minTime)
                    minTime = totalTime;
            }
        }

        return minTime;
    }
};


// Simpler solution: Traverse through both combination in the same loop and calculate the total time for both combinations and update the minimum time accordingly.
// Time Complexity: O(n*m) where n is the number of land rides and m is the number of water rides.
// We have two nested loops, the outer loop iterates through the land rides and the inner loop iterates through the water rides.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the minTime variable.

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int minTime = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                //land->water
                int landFinish = landStartTime[i]+landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                minTime = min(minTime, waterStart+waterDuration[j]);

                //water->land
                int waterFinish = waterStartTime[j]+waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);
                minTime = min(minTime, landStart+landDuration[i]);

            }
        }

        return minTime;
        
    }
};