// https://leetcode.com/problems/maximum-points-after-enemy-battles

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int sum=currentEnergy;
        for(int i=enemyEnergies.size()-1;i>=1;i--){
            sum+=enemyEnergies[i];
        }
        return sum/enemyEnergies[0];
    }
};