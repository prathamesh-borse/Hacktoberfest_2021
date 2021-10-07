
//Problem Link: https://practice.geeksforgeeks.org/problems/water-connection-problem5822/1


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    pair<int,int> dfs(unordered_map<int, pair<int, int>> &g, int u)
    {
       if(g.find(u) == g.end()) return {u, INT_MAX};
       
       auto p = dfs(g, g[u].first);
       int min_dia = min(g[u].second, p.second);
       
       return {p.first, min_dia};
    }
   
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
       unordered_set<int> t;
       for(int i=0; i<p; i++) t.insert(b[i]);
       
       unordered_map<int, pair<int, int>> g;
       for(int i=0; i<p; i++)
           g[a[i]] = {b[i], d[i]};
       
       vector<vector<int>> res;
       for(int i=1; i<=n; i++)
       {
           if(g.find(i) != g.end() && t.find(i) == t.end())
           {
               auto p = dfs(g, i);
               res.push_back({i, p.first, p.second});
           }
       }
       
       return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends
