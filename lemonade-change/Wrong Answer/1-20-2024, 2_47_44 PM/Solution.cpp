// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>mp;
        bool check=true;
        for(int i=0;i<bills.size();i++){
            if(bills[i]-5!=0){
                int change=bills[i]-5;
                mp[bills[i]]++;
                if(bills[i]==10){
                    mp[10]++;
                    if(mp[5]<=0){
                        return false;
                    }
                    else{
                        mp[5]--;
                    }
                }
                else if(bills[i]==20){
                    mp[20]++;
                    if(mp[5]<=0 or mp[10]<=0){
                        return false;
                    }
                    else{
                        mp[5]--;
                        mp[10]--;
                    }
                }
            }
            else{
                mp[bills[i]]++;
            }
        }
        return check;
    }
};