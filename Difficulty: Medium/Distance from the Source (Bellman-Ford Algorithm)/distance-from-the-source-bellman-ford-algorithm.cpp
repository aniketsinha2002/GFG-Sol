//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& edges, int S) {
        vector<int> distance(n, 1e8);
        distance[S] = 0;
        
        //relaxation for V-1 time accn to Bellman Ford
        for(int count = 1; count <= n-1; count ++)
        {
            for (auto& edge: edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(distance[u] != 1e8) //means we already reached u now we can reach v
                {
                    if(distance[u] + w < distance[v])
                    {
                        distance[v] = distance[u] + w;
                    }
                }
            }
        }
        
        //now if -ve edge is there  it'll continue to run in infinite loop,
        //so check by doing one more relaxation
        
        for (auto& edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(distance[u] != 1e8) //means we already reached u now we can reach v
            {
                if(distance[u] + w < distance[v])
                {
                    return {-1}; //-ve cycle detected
                }
            }
        }
            
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends