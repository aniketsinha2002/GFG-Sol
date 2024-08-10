//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        int source = 1;

        // constructing the adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
    
        for(auto vec: edges){
            auto u = vec[0];
            auto v = vec[1];
            auto wt = vec[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    
        // priority queue to store {distance, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
        // distances from source to each node(ndexes)
        vector<int> result(n + 1, INT_MAX);
    
        // parent of each node for path reconstruction
        vector<int> parent(n + 1, -1);
    
        // initialize parent vector
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    
        // source to source distance
        result[source] = 0;
        pq.push({0, source}); // {distance, node}
    
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            
            int dist = top.first;
            int u = top.second;
    
            // visit adjacent nodes
            for (auto &v : adj[u]) {
                int adjNode = v.first;
                int adjDist = v.second;
    
                if (adjDist + dist < result[adjNode]) {
                    result[adjNode] = adjDist + dist;
                    pq.push({adjDist + dist, adjNode});
    
                    // update parent of adjNode
                    parent[adjNode] = u;
                }
            }
        }
    
        // edge case: if destination is unreachable
        int destNode = n;
        if (result[destNode] == INT_MAX) return {-1};
    
        // reconstruct path from destination to source using parent array
        vector<int> path;
    
        while (parent[destNode] != destNode) {
            path.push_back(destNode);
            destNode = parent[destNode];
        }
    
        // add the source node to the path
        path.push_back(source);
        
        // pushing the max dist as req in the problem statement
        //restlt vec will store -> dist from source to i -> 
        //at idx n -> dist from source to n-> which is our req max dist
        path.push_back(result[n]);
        
        // reverse to get the path from source to destination
        reverse(path.begin(), path.end());
    
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends