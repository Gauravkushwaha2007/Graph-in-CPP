#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int n;
    list <int> *adj;

    Graph(int node){
        n = node;
        adj = new list<int>[n];
    }

    void insert(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS_traversal(int start){
        vector <bool> visited (n, false);
        queue <int> Q;
        visited [start] = true;
        Q.push(start);

        while(Q.size()> 0){
            int node = Q.front();
            Q.pop();
            cout<< node <<" \n";
            for(int val : adj[node]){
                if(!visited[val]){
                    visited[val] = true;
                    Q.push(val);
                }
            }
        }
    }


};


    
