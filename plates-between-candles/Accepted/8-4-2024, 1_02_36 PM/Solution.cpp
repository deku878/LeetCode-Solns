// https://leetcode.com/problems/plates-between-candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>pref(n);
        if(s[0] == '*')
            pref[0] = 1;
        else
            pref[0] = 0;
        
        for(int i=1;i<n;i++)
            if(s[i] == '*')
                pref[i] = pref[i-1]+1;
            else
                pref[i] = pref[i-1];
        
        
        vector<int>candle;
        for(int i=0;i<s.length();i++)
            if(s[i] == '|')
                candle.push_back(i);
        
        
        vector<int>ans;
        
        
        for(int i=0;i<queries.size();i++)
        {
            if(candle.size() <= 1)
            {
                ans.push_back(0);
                continue;
            }
            int first = queries[i][0];
            int second = queries[i][1];
            
            int pos1 = lower_bound(candle.begin(),candle.end(),first)-candle.begin();
            int pos2 = --upper_bound(candle.begin(),candle.end(),second)-candle.begin();
            // cout<<candle[pos1]<<" "<<candle[pos2]<<endl;
            
            if(pos1 >= candle.size() || pos2 < 0 || pos1>=pos2)
                ans.push_back(0);
            else
                ans.push_back(pref[candle[pos2]]-pref[candle[pos1]]);
            
        }
        return ans;
    }
};