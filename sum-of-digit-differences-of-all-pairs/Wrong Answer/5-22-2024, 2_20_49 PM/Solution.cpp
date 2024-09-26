// https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string>p;
        for(int i=0;i<nums.size();i++){
            p.push_back(to_string(nums[i]));
        }
        map<int,int>mp,mp1,mp2,mp3,mp4,mp5;
        for(int i=0;i<p.size();i++){
            string x=p[i];
            for(int j=0;j<p[i].size();j++){
                if(j==0){
                mp[x[j]-'0']++;}
                else if(j==1){
                mp1[x[j]-'0']++;
                }
                else if(j==2){
                mp2[x[j]-'0']++;
                }
                else if(j==3){
                mp3[x[j]-'0']++;
                }
                else if(j==4){
                mp4[x[j]-'0']++;
                }
                else if(j==5){
                mp5[x[j]-'0']++;
                }
            }
        }
        long long int sum=p.size(),sum1=p.size(),sum2=p.size(),sum3=p.size(),sum4=p.size(),sum5=p.size();
        long long int ans=0;
        for(int i=0;i<p.size();i++){
            string y=p[i];

            for(int j=0;j<y.size();j++){
                if(j==0){
                    ans+=(sum-mp[y[j]-'0'])*mp[y[j]-'0'];
                    sum-=mp[y[j]-'0'];
                    mp[y[j]-'0']=0;
                }
                else if(j==1){
                    ans+=(sum1-mp1[y[j]-'0'])*mp1[y[j]-'0'];
                    sum1-=mp1[y[j]-'0'];
                    mp1[y[j]-'0']=0;
                }
                else if(j==2){
                    ans+=(sum2-mp2[y[j]-'0'])*mp2[y[j]-'0'];
                    sum2-=mp2[y[j]-'0'];
                    mp2[y[j]-'0']=0;
                }
                else if(j==3){
                     ans+=(sum3-mp3[y[j]-'0'])*mp3[y[j]-'0'];
                     sum3-=mp3[y[j]-'0'];
                     mp3[y[j]-'0']=0;
                }
                else if(j==4){
                     ans+=(sum4-mp4[y[j]-'0'])*mp4[y[j]-'0'];
                    sum4-=mp4[y[j]-'0'];
                     mp4[y[j]-'0']=0; 
                }
                else if(j==5){
                    ans+=(sum5-mp5[y[j]-'0'])*mp5[y[j]-'0'];
                    sum5-=mp5[y[j]-'0'];
                    mp5[y[j]-'0']=0;
                }
            }
        }
        return ans;
    }
};