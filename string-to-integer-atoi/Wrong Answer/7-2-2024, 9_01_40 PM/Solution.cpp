// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string s) {
        //base cases
        //first check if the character at the 0th index
        bool check=false;
        int index=0;
        long long int maximum=INT_MAX;
        long long int minimum=INT_MIN;
        while(index<s.size() and s[index]==' '){
            index++;
        }
        long long int ans=0;
        if(s[index]=='-'){
            index++;
            while(index<s.size() and s[index]=='0'){
                index++;
            }
            long long int curr=0;
            for(int i=index;i<s.size();i++){
                if(s[i]>='1' and s[i]<='9'){
                    int val=s[i]-'0';
                    curr=curr*10;
                    curr=curr+val;
                }
                else{
                    break;
                }
            }
            curr=curr*(-1);
            ans=curr;
        }
        else{
            while(index<s.size() and s[index]=='0'){
                index++;
            }
            long long int curr=0;
            for(int i=index;i<s.size();i++){
                if(s[i]>='1' and s[i]<='9'){
                    int val=s[i]-'0';
                    curr=curr*10;
                    curr=curr+val;
                }
                else{
                    break;
                }
            }
            ans=curr;
        }
        if(ans>=maximum){
            return maximum;
        }
        if(ans<=minimum){
            return minimum;
        }
        return ans;
    }
};