// https://leetcode.com/problems/largest-number

class Solution {
public:
    static bool cmp(string &s,string &t){
        string y=s+t;
        string z=t+s;
        for(int i=0;i<y.size();i++){
            if((y[i])-'0'>(z[i]-'0')){
                return true;
            }
            if((y[i]-'0')<(z[i]-'0')){
                return false;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>x;
        int n=nums.size();
        for(int i=0;i<n;i++){
            string y=to_string(nums[i]);
            x.push_back(y);
        }
        sort(x.begin(),x.end(),cmp);
        //constraint chutia hh should i look for optimal?lol
        string u="";
        for(int i=0;i<x.size();i++){
            u+=x[i];
        }
        if(count(u.begin(),u.end(),'0')==u.size()){
            return "0";
        }
        else if(u[0]=='0'){
        int i=0;
        while(u[i]=='0'){
            i++;
        }
        string h="";
        for(int k=i;k<u.size();i++){
            h+=u[i];
        }
        return h;
        }
        return u;
    }
};