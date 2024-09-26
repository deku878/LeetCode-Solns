// https://leetcode.com/problems/maximum-points-after-enemy-battles

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0]>currentEnergy){
            return 0;
        }
        else{
            if(enemyEnergies.size()==1){
                return currentEnergy/enemyEnergies[0];
            }
            else{
                return enemyEnergies.size();
            }
        }
    }
};