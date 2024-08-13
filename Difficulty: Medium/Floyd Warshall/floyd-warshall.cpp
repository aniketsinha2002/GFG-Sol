//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&grid)
	{
	    int n = grid.size(); // size of the grid
	    
	    //accn to question for our benifit -> as we will use min so convert -1 to temp max
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == -1) // Assuming you want to check for -1
                    grid[i][j] = 100000; // Set the value to 100000
            }
        }
        
        //Floyd Warshall Algo -> go through all via and check for all edges
        for (int via = 0; via < n; via++) // all via vertices
        { 
            for (int i = 0; i < n; i++) //all vertices combination of source and destination
            {
                for (int j = 0; j < n; j++) 
                {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }
        
        
        // for (int j = 0; j < n; j++) { // after going through via source to source val is -ve -> diagonal check
        //     if (grid[i][j] is negative) 
        //         its a cycle
        // }
        
        //rechagging the -1 to correct given order
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 100000) 
                    grid[i][j] = -1; 
            }
        }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends