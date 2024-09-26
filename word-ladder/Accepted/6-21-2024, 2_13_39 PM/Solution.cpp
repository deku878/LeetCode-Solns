// https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       queue<string>q;
       q.push(beginWord);
       set<string>x1;
       for(int i=0;i<wordList.size();i++){
        if(wordList[i]!=beginWord){
        x1.insert(wordList[i]);}
       }
       int moves=0;
       bool flag=false;
       while(!q.empty()){
        int sz=q.size();
        while(sz--){
            auto x=q.front();
            q.pop();
            if(x==endWord){
                return moves+1;
            }
            string r=x;
            for(int j=0;j<x.size();j++){
                for(char t='a';t<='z';t++){
                    r[j]=t;
                    if(x1.find(r)!=x1.end()){
                        q.push(r);
                        x1.erase(x1.find(r));
                    }
                }
                r=x;
            }
        }

        moves++;
       }
       return 0;
    }
};