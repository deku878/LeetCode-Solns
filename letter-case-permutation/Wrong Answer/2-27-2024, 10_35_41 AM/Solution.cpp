// https://leetcode.com/problems/letter-case-permutation

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        vector<string>p;
        for(int i=0;i<(1<<n);i++){
            string x="";
            for(int j=0;j<n;j++){
                if((1<<j) & i){
                    if(s[j]<='z' and s[j]>='a'){
                        x+=s[j]-32;
                    }
                    else{
                        x+=s[j];
                    }
                }
                else{
                        x+=s[j];
                    }
            }
            if(find(p.begin(),p.end(),x)==p.end()){
            p.push_back(x);}
        }
        return p;
    }
};