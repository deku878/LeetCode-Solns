// https://leetcode.com/problems/slowest-key

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev=0;
        int res=INT_MIN;
        char p;
        for(int i=0;i<releaseTimes.size();i++){
            if(releaseTimes[i]-prev>res){
                res=releaseTimes[i]-prev;
                p=keysPressed[i];
            }
            else if((releaseTimes[i]-prev)==res){
                if(p<keysPressed[i]){
                    p=keysPressed[i];
                }
            }
            cout<<prev<<endl;
            prev=releaseTimes[i];
        }
        return p;
    }
};