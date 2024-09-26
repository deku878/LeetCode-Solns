// https://leetcode.com/problems/robot-bounded-in-circle

class Solution {
public:
    bool isRobotBounded(string s) {
        //north-positive
        //south-negative
        //east-positive
        //west-negative
        int x1=0;
        int x2=0;
        int inv=0;
        vector<char>lo={'N','E','S','W'};
        int idx=0;
        bool y=true;
        bool x=false;
        map<pair<int,int>,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='G'){
              idx=(lo.size()+inv)%(lo.size());
              cout<<idx<<endl;
              if(lo[idx]=='N'){
                x2++;
                mp[{x1,x2}]++;
                
              }
              else if(lo[idx]=='W'){
                x1--;
                mp[{x1,x2}]++;
              }
              else if(lo[idx]=='E'){
                x1++;
                mp[{x1,x2}]++;
              }
              else{
                x2--;
                mp[{x1,x2}]++;
              }
            }
            else if(s[i]=='L'){
            inv-=1;
            }
            else{
            inv+=1;
            }
             idx=(lo.size()+inv)%(lo.size());
            if(x1==0 and x2==0){
                return true;
            }
            else if(idx!=0){
                return true;
            }
        }
        for(auto m:mp){
            cout<<m.first.first<<" "<<m.first.second<<endl;
        }
        return false;
    }
};