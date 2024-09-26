// https://leetcode.com/problems/largest-plus-sign

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> l(n,vector<int> (n,0)),r=l,u=l,d=l;
        vector<vector<int>> m(n,vector<int> (n,1));

        for(auto i : mines)
        m[i[0]][i[1]]=0;

        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(m[i][j]==0) c=0;
                else c++;
                l[i][j]=c;
            }
        }
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=n-1;j>=0;j--)
            {
                if(m[i][j]==0) c=0;
                else c++;
                r[i][j]=c;
            }
        }
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(m[j][i]==0) c=0;
                else c++;
                u[j][i]=c;
            }
        }
         for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=n-1;j>=0;j--)
            {
                if(m[j][i]==0) c=0;
                else c++;
                d[j][i]=c;
            }
        }
        int a=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a=max(a,min({l[i][j],r[i][j],u[i][j],d[i][j]}));

        return a;

    }
};
