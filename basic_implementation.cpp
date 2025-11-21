#include<iostream>
#include<list>
using namespace std;

class Graph{
    int n;
    list <int> *adj;

    Graph(int node){
        n= node;
        adj = new list<int>[n];
    }

    void insert(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display(){
        for(int i=0; i<n; i++){
            cout << i << " : ";
            for(int neighbour: adj[i]){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(5);
    g.insert(0,1);
    g.insert(0,2);
    g.insert(1,3);
    g.insert(2,3);
    g.display();
    return 0;
}
