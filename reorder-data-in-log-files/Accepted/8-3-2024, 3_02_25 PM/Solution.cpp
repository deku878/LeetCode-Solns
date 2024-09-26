// https://leetcode.com/problems/reorder-data-in-log-files

class Solution {
public:
    static bool cmp(const string&a,const string&b){
        int posA = a.find(' ');
        int posB = b.find(' ');

        // Extract the content of the logs (excluding the identifier)
        string contentA = a.substr(posA + 1);
        string contentB = b.substr(posB + 1);

        // Compare the contents
        if (contentA != contentB) {
            return contentA < contentB;
        }

        // If the contents are the same, compare the identifiers
        return a < b;

    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string>lo;
        for(int i=0;i<logs.size();i++){
            if(logs[i][logs[i].size()-1]<='z' and logs[i][logs[i].size()-1]>='a'){
                lo.push_back(logs[i]);
            }
        }
        sort(lo.begin(),lo.end(),cmp);
        for(int i=0;i<logs.size();i++){
            if(logs[i][logs[i].size()-1]<='9' and logs[i][logs[i].size()-1]>='0'){
                lo.push_back(logs[i]);
            }
        }
        return lo;
    }
};