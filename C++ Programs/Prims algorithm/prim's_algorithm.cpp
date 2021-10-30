#include <bits/stdc++.h> 
using namespace std;

#define V 9 // vertices in the graph
// A function to find the vertex with minimum key value, 
//from the set of vertices not yet included in MST 
int find_min_key(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index;  // Initializing min value 
	for (int v = 0; v < V; v++) 
	{
		if (mstSet[v] == false && key[v] < min) 
		{
			min = key[v], min_index = v; 
		}
	}
	return min_index; 
} 

void min_st_printing(int parent[], int graph[V][V],map<int ,char > mp) // A function to print the constructed MST stored in parent[] 
{ 
	cout<<"Edges included in the minimum spanning tree are :\n";
	cout<<"Edge \tWeight\n"; 
	int sum = 0;
	for (int i = 1; i < V; i++) 
	{
		cout<<mp[parent[i]]<<" - "<<mp[i]<<" \t"<<graph[i][parent[i]]<<" \n"; 
		sum+=graph[i][parent[i]];
	}
	cout<<"Weight of Minimum Spanning Tree is : "<<sum<<endl;
} 

void mst_by_prim(int graph[V][V],map<int ,char > mp)  // Function to construct and print MST for this graph
{  
	int parent[V];  // Array to store constructed MST
	int key[V];    // Key values used to pick minimum weight edge in cut 
	bool mstSet[V]; // To represent set of vertices included in MST 
	
	for (int i = 0; i < V; i++)  // Initialize all keys as INFINITE 
	{
		key[i] = INT_MAX, mstSet[i] = false; 
	}

	key[0] = 0; 
	parent[0] = -1; // First node is always root of MST 
	
	for (int count = 0; count < V - 1; count++)  // The MST will have V vertices 
	{ 
		// Picking the minimum key vertex from the set of vertices not yet included in MST 
		int u = find_min_key(key, mstSet); 
		
		mstSet[u] = true;  // Adding the picked vertex to the MST Set 

		// Update key value and parent index of the adjacent vertices of the picked vertex. 
		// Consider only those vertices which are not yet included in MST 
		for (int v = 0; v < V; v++) 
		    // graph[u][v] is non zero only for adjacent vertices of m 
	        // mstSet[v] is false for vertices not yet included in MST 
			// Update the key only if graph[u][v] is smaller than key[v] 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
			{
				parent[v] = u, key[v] = graph[u][v]; 
			}
	} 
	min_st_printing(parent, graph,mp); 	// print the constructed MST 
} 
int main() 
{
	freopen("In.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int graph[V][V];
	map<int ,char > mp;
	for(int i=0;i<V;i++)
	{
		char c;
		cin>>c;
		mp[i] = c;
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cin>>graph[i][j];
		}
	}
	mst_by_prim(graph,mp); 
	return 0; 
} 
