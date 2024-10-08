//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends

// FIND UNION BY RANK 
//parent of each nodes stored in parent array and given as input
//if rank equal -> make any one parent and uska rank do +1
//else jiska rank jyada hoga wo PAPA banega 0_0

int find(int parent[],int x)
{
    if(x == parent[x])
        return x;
        
    int top_parent = find(parent, parent[x]);
    
    //while comming back from recursion -> update the parent what we got from top
    //path compression
    parent[x] = top_parent;
    
    return parent[x];
}

//find the parent of x and y and if both are not in same set we can merge them
void unionSet(int parent[],int x,int y)
{
	int parent_x = find(parent, x);
	int parent_y = find(parent, y);
	
	
// 	if(parent_x == parent_y)
// 	    return ;
	    
// 	if(rank[parent_x] > rank[y_parent])
// 	{
// 	    parent[parent_x] = parent_y;
// 	}
// 	else if(rank[parent_x] < rank[y_parent])
// 	{
// 	    parent[parent_y] = parent_x;
// 	}
// 	else //if equal
// 	{
// 	    parent[parent_x] = parent_y;
// 	    rank[parent_y] ++;
// 	}
	
	if(parent_x != parent_y)
	{
	    parent[parent_x] = parent_y;
	}
}