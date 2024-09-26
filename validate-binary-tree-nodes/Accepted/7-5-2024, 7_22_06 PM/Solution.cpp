// https://leetcode.com/problems/validate-binary-tree-nodes

class DSU
{
    public:
    vector<int>parent;
    DSU(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int Find(int x)
    {
        if(x!=parent[x])
            parent[x]=Find(parent[x]);
        return parent[x];
    }
    void Union(int a,int b)
    {
        parent[Find(a)]=Find(b);
    }
    int _components(int n)
    {
        unordered_set<int>_set;
        for(int i=0;i<n;i++)
            _set.insert(Find(i));
        return _set.size();
    }
};
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) 
    {
        DSU dsu=DSU(n);
        for(int i=0;i<n;i++)
        {
            if(l[i]!=-1)
            {
                int pa=dsu.Find(i);
                int pb=dsu.Find(l[i]);
                if(pa!=pb)
                {
                    dsu.Union(i,l[i]);
                }
                else
                    return false;
            }
            if(r[i]!=-1)
            {
                int pa=dsu.Find(i);
                int pb=dsu.Find(r[i]);
                if(pa!=pb)
                {
                    dsu.Union(i,r[i]);
                }
                else
                    return false;
            }
        }
        vector<int>incom(n,0);
        for(int i=0;i<n;i++)
        {
            if(l[i]!=-1)
                incom[l[i]]++;
            if(r[i]!=-1)
                incom[r[i]]++;
        }
        for(int x:incom)
            if(x>1)
                return false;
        return dsu._components(n)==1;
    }
};
