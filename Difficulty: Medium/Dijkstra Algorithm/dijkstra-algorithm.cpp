//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int source)
    {
        //this pq will be storing distances and destination from source
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //sorce to index distances
        vector<int> ans(n,INT_MAX);
        
        //source to source distance when our destination = source 
        ans[source] = 0;
        
        pq.push({0,source}); //distance destination
        
        
        while(!pq.empty())
        {
            int dist = pq.top().first; //0
            int u = pq.top().second; // 2
            pq.pop();
            
            for(auto& v: adj[u])
            {
                int adjNode = v[0]; //1
                int adjDist = v[1]; //3
                
                //going form 2 to 1 = going from 2 to 2 + going from 2 to 1 = 0 + 3
                if(dist + adjDist <= ans[adjNode])
                {
                    ans[adjNode] = dist + adjDist;
                    pq.push({dist + adjDist, adjNode});
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends