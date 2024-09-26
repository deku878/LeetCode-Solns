// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& h, int k) {
        map<int,int>mp;
        for(int i=0;i<h.size();i++){
            mp[h[i]]++;
        }
        while(!mp.empty()){
            int curr=mp.begin()->first;
            for(int i=0;i<k;i++){
                if(mp[curr+i]==0){
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]<1){
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};