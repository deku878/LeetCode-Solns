// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        for(int x:hand)
        {
            mp[x]++;
        }
        for(auto it:mp)
        {
            if(mp[it.first]>0)
            {
                for(int i=1;i<groupSize;i++)
                {
                    mp[it.first+i]-=mp[it.first];
                    if(mp[it.first+i]<0)
                    return false;
                }
            }

        }
        return true;
    }
};