#include <bits/stdc++.h>
using namespace std;

class Edge  // a structure to represent a weighted edge in graph
{
	public:
	int src, dest, weight;
};

class Graph  // a structure to represent a connected, undirected and weighted graph
{
	public:
	int V, E;  // V->vertices, E-> edges
	// graph is represented as an array of edges.
	// graph is undirected so des to src or src to des , is cosidered as a one edge.
	Edge* edge;
	Graph(int V,int E)
	{
		this->V = V;
		this->E = E;
		edge = new Edge[E];
	}
};

class subset  // A structure to represent a subset for union-find
{
	public:
	int parent;
	int rank;
};

int find(subset subsets[], int i) // A function to find set of an element i (uses path compression technique)
{
	if (subsets[i].parent != i) // find root and make root as parent of i (path compression)
	{
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)  // A function that does union of two sets of x and y (uses union by rank)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	
	if (subsets[xroot].rank < subsets[yroot].rank) // Attach smaller rank tree under root of high rank tree (Union by Rank)
	subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
	subsets[yroot].parent = xroot;
	else  // If ranks are same, then make one as root and increment its rank by one
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void* a, const void* b) // Compare two edges according to their weights.
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->weight > b1->weight;
}

void mst_by_kruskal(Graph* graph,map<int, char > mp) // function to find mst using kruskals algo
{
	int V = graph->V; 
	Edge result[V]; // This will store the resultant MST
	int e = 0; // An index variable, used for result[]
	int i = 0; // An index variable, used for sorted edge 
    // Step 1: Sort all the edges in non-decreasing order of their weight. If we are not allowed
	// to change the given graph, we can create a copy of array of edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),myComp); // Using qsort() for sorting an array of edges
	subset* subsets = new subset[(V * sizeof(subset))]; // Allocate memory for creating V ssubsets
	
	for (int v = 0; v < V; ++v)  // Creating V subsets with single elements
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	
	while (e < V - 1 && i < graph->E)  // Number of edges to be taken is equal to V-1
	{
		// Step 2: Pick the smallest edge. And increment the index for next iteration
		Edge next_edge = graph->edge[i++];
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);
		// If including this edge does't cause cycle,
		if (x != y) // include it in result and increment the index of result for next edge
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}// Else discard the next_edge
	}
	
	cout << "Edges in the Minimum Spanning Tree are :\n"; // print the contents of result[] to display the built MST
	int minimumCost = 0;
	for (i = 0; i < e; ++i) 
	{
		cout << mp[result[i].src] << " "<< mp[result[i].dest]<<" "<< result[i].weight << endl;
		minimumCost = minimumCost + result[i].weight;
	}
	cout << "Minimum Spanning Tree's weight is :  " << minimumCost<< endl;
}

int main() 
{
	freopen("Input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int V = 9, E = 14;
	Graph* graph = new Graph(V, E);
	map<int ,char > mp;
	for(int i=0;i<V;i++)
	{
		char c;
		cin>>c;
		mp[i] = c;
	}
	for(int i=0;i<E;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		graph->edge[i].src = u;
		graph->edge[i].dest = v;
		graph->edge[i].weight = wt;
	}
	mst_by_kruskal(graph,mp); 
	return 0; 
} 
