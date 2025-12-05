#include <iostream>
#include <vector>
#include <list>
using namespace std;


class Graph {
public:
    int n;
    list<int> *adj;

    Graph(int n){
        this->n = n;
        adj = new list<int>[n];
    }


    void insert(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool helper_cycle(int start, int parent, vector<bool>& vis) {
        vis[start] = true;

        for(int nei : adj[start]) {
            if(!vis[nei]) {
                if(helper_cycle(nei, start, vis)) 
                    return true;
            }
            else if(nei != parent) {
                return true;  // cycle found
            }
        }
        return false;
    }


    bool is_cycle(int start) {
        vector<bool> vis(n, false);
        return helper_cycle(start, -1, vis);
    }
};



int main(){
    Graph g(6);
    g.insert(0,1);
    g.insert(1,3);
    g.insert(2,3);
    g.insert(3,5);
    g.insert(2,5);
    if(g.is_cycle(0)) cout<< "Cycle found ";
    else cout<< "Cycle not found";
    return 0;
}
