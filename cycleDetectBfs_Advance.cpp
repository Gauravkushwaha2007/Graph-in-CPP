#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;


class Graph{
    public: 
    int n;
    list <int> *adj;
    Graph(int n){
        this-> n = n;
        adj = new list<int> [n];
    }

    void insert(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCycleCore(int src, vector <bool> &vis){
        queue <pair <int,int>> q;
        vis[src ]= true;
        q.push({src, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int nbr: adj[node]){
                if(!vis[nbr]){
                    vis[nbr]= true;
                    q.push({nbr, parent});
                }
                else if(nbr != parent) return true;
            }
        }
        return false;
    }

    bool isCycleMain(int src){
        vector <bool> vis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycleCore(i, vis)) return true;
            }
        }
        return false;
    }
};
int main(){

    Graph g(6);
    g.insert(0,1);
    g.insert(0,2);
    g.insert(1,3);
    g.insert(3,4);
    g.insert(4,5);
    if(g.isCycleMain(0)){
        cout<< "\nYess! cycle exist.\n";
    } 
    else{
        cout<< "Cyle doesn't exist! ";
    }

    return 0;
}