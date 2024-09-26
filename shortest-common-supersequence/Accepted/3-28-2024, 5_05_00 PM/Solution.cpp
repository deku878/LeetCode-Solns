// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
     
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        // int i=n;
        // int j=m;
        // string str="";
        // while(i!=0&&j!=0){
        //     if(str1[i-1]==str[j-1]){
        //         str.push_back(str1[i-1]);
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i][j-1] > dp[i-1][j]){
        //         j--;
        //     }
        //     else{
        //         i--;
        //     }
        // }
        // reverse(str.begin(),str.end());
         
        // string modified=str1;

        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<str.length();j++){
        //         if(str[j]==modified[i]){
        //             modified.erase(i,1);
        //             break;
        //         }
        //     }

        // }

        // string result=modified+str2;

        // return result;
         int i = n;
    int j = m;
    string str = "";
    while (i > 0 && j > 0) {  // Corrected condition
        if (str1[i-1] == str2[j-1]) {
            str.push_back(str1[i-1]);
            i--;
            j--;
        }
        else if (dp[i][j-1] > dp[i-1][j]) {
            str.push_back(str2[j-1]);  // Append character from str2
            j--;
        }
        else {
            str.push_back(str1[i-1]);  // Append character from str1
            i--;
        }
    }

    while (i > 0) {
        str.push_back(str1[i-1]);
        i--;
    }

    while (j > 0) {
        str.push_back(str2[j-1]);
        j--;
    }

    reverse(str.begin(), str.end());

    return str;

        
    }
};