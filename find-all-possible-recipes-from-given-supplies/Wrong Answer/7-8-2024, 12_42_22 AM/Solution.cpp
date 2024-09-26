// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int>mp;
        for(int i=0;i<supplies.size();i++){
            mp[supplies[i]]++;
        }
        int n=recipes.size();
        vector<string>adj[n];
        for(int i=0;i<n;i++){
            for(auto x:ingredients[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>k;
        for(int i=0;i<n;i++){
            int x1=adj[i].size();
            for(auto x:adj[i]){
                if(mp.count(x)!=0){
                    x1--;
                }
            }
            if(x1<=0){
                mp[recipes[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            int x1=adj[i].size();
            for(auto x:adj[i]){
                if(mp.count(x)!=0){
                    x1--;
                }
            }
            if(x1<=0){
                k.push_back(i);
            }
        }
        vector<string>y;
        for(int i=0;i<k.size();i++){
            y.push_back(recipes[k[i]]);
        }
        return y;
    }
};