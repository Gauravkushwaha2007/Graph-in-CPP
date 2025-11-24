#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public: 
    int n;
    list <int> *adj;
    Graph(int node){
        n = node;
        adj = new list <int> [n];
    }

    void insert(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS_help(int node, vector<bool> &visited){
        visited[node] = true;
        cout<< node<< " ";

        for(int neighbour: adj[node]){
            if(!visited[neighbour]){
                DFS_help(neighbour, visited);
            } 
        }
    }

    void DFS_traversal(int start){
        vector <bool> vis(n,false);
        DFS_help(start, vis);
    }
};

int main(){
    Graph g(5);
    g.insert(0,1);
    g.insert(0,2);
    g.insert(1,3);
    g.insert(2,4);
    g.DFS_traversal(0);

    return  0;
}
