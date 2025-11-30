#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    public:
    int n;
    list<int> *adj;

    Graph(int node){
        n = node;
        adj = new list<int> [n];
    }

    void insert(int f, int s){
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    void display(){
        for(int i=0; i<n; i++){
            cout<< i << " : ";  
            for(int neighbour : adj[i]){
                cout<< neighbour << " ";
            }
            cout <<  endl;
        }
    }

    void BFS_traversal(int start){
        queue <int> Q;
        vector <bool> visited(n, false);
        visited[start] = true;
        Q.push(start);

        while(!Q.empty()){
            int node = Q.front();
            Q.pop();
            cout<< node <<" ";
            for(int neigh : adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    Q.push(neigh);
                }
            }
        }
    }
    
};

int main(){
    Graph g(6);
    g.insert(0,2);
    g.insert(0,3);
    g.insert(1,3);
    g.insert(1,5);
    g.insert(1,2);
    g.insert(2,4);
    g.BFS_traversal(0);
}

