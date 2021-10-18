#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{

    map <T,list<T>> l;
    int V;

public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(T x, T y){
        l[x].push_back(y);
    }

    void toplogSortBfs(){

        int *indegree = new int[V];

        for (int i = 0; i < V; ++i)
        {
            indegree[i] = 0;
        }

        for(auto node_pair : l){

            for(auto nbr : node_pair.second ){
                indegree[nbr]++;
            }
        }

        queue <T> q;

        for (int i = 0; i < V; ++i)
        {
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto nbr : l[node]){
                indegree[nbr]--;

                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }

};

int main()
{
    Graph <int> g(6);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.toplogSortBfs();

    return 0;
}

