//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // FIND UNION BY RANK WITH PATH COMPRESSION
    //parent of each nodes stored in parent array
    //if rank equal -> make any one parent and uska rank do +1
    //else jiska rank jyada hoga wo PAPA banega 0_0
    
    vector<int> rank;
    vector<int> parent;
    
    int find(int x)
    {
        if(x == parent[x])
            return x;
            
        int top_parent = find(parent[x]);
        
        //while comming back from recursion -> update the parent what we got from top
        //path compression
        parent[x] = top_parent;
        
        return parent[x];
    }
    
    //find the parent of x and y and if both are not in same set we can merge them
    void unionSet(int x,int y)
    {
    	int parent_x = find(x);
    	int parent_y = find(y);
    	
    	
    	if(parent_x == parent_y)
    	    return ;
    	    
    	if(rank[parent_x] > rank[parent_y])
    	{
    	    parent[parent_y] = parent_x;
    	}
    	else if(rank[parent_x] < rank[parent_y])
    	{
    	    parent[parent_x] = parent_y;
    	}
    	else //if equal
    	{
    	    parent[parent_x] = parent_y;
    	    rank[parent_y] ++;
    	}
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int n, vector<int>adj[])
	{
	    //parent and rank initilization
	    rank.resize(n, 0);
        parent.resize(n);
        
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
        
        //vititing nodes
	    for(int u=0; u< n; u++)
	    {
	        for(auto &v: adj[u])
	        {
	            if(u<v) //to not go again to visited
	            {
	                int parent_u = find(u);
	                int parent_v = find(v);
	                
	                if(parent_u == parent_v) return 1;
	                else unionSet(u,v);
	           }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends