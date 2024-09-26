// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char,long long int>>vc;
        vector<pair<char,long long int>>p;
        long long int count=1;
        char prev=name[0];
        for(int i=1;i<name.size();i++){
            if(prev==name[i]){
                count++;
            }
            else{
                vc.push_back({prev,count});
                count=1;
                prev=name[i];
            }
        }
        if(count>=1){
            vc.push_back({prev,count});
        }
        count=1;
        prev=typed[0];
        for(int i=1;i<typed.size();i++){
            if(prev==typed[i]){
                count++;
            }
            else{
                p.push_back({prev,count});
                count=1;
                prev=typed[i];
            }
        }
        if(count>=1){
            p.push_back({prev,count});
        }
        if(p.size()<vc.size()){
            return false;
        }
        for(int i=0;i<vc.size();i++){
            if(p[i].first!=vc[i].first){
                return false;
            }
            if(p[i].second<vc[i].second){
                return false;
            }
        }
        return true;
    }
};