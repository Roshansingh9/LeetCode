class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {

                // Land → Water
                int landStart = landStartTime[i];
                int landFinish = landStart + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int waterFinish = waterStart + waterDuration[j];
                minFinishTime = min(minFinishTime, waterFinish);

                // Water → Land
                int waterStart2 = waterStartTime[j];
                int waterFinish2 = waterStart2 + waterDuration[j];
                int landStart2 = max(waterFinish2, landStartTime[i]);
                int landFinish2 = landStart2 + landDuration[i];
                minFinishTime = min(minFinishTime, landFinish2);
            }
        }

        return minFinishTime; 
    }
};