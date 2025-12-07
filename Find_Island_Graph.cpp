#include <iostream>
#include <vector>

using namespace std;

void helper(int i, int j, vector<vector<int>>& grid, int n, int m) {
    if(i< 0 || j<0 || i>=n || j >=m || grid[i][j] == 0) {return;}
    
    grid[i][j] = 0;
    helper(i+1, j, grid, n, m);
    helper(i-1, j, grid, n, m);
    helper(i, j+1, grid, n, m);
    helper(i, j-1, grid, n, m);
}

int numIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int totalIland = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                totalIland++;     
              helper(i, j, grid, n, m);
            }
        }
    }
    return totalIland;
}




int main() {
    vector<vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,1},
        {0,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}
    };

    cout << numIslands(grid);
return 0;
}
