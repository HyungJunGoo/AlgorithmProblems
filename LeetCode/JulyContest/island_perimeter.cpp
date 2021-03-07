#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int height = grid.size();
        for(int i=0; i<height; i++){
            int width = grid[i].size();
            for(int j=0; j<width; j++){
                if(grid[i][j] == 1){
                    if(i == 0){
                        perimeter++;
                    }
                    if(j == 0){
                        perimeter++;
                    }
                    if(i == height-1){
                        perimeter++;
                    }
                    if(j == width-1){
                        perimeter++;
                    }
                    if(j-1>=0 || j+1 < width){
                        if(j-1>=0 && grid[i][j-1] == 0 ) perimeter++;
                        if(j+1<width && grid[i][j+1] == 0 ) perimeter++;
                    }
                    if(i-1>=0 || i+1 < height){
                        if(i-1>=0 && grid[i-1][j] == 0 ) perimeter++;
                        if(i+1<height && grid[i+1][j] == 0 ) perimeter++;
                    }
                }
                else{
                    continue;
                }
            }
        }
        return perimeter;
    }
};

int main(){
    Solution s;
    vector<vector<int> > grid1 = {{0,1}};
    vector<vector<int> > grid2 = {{1,0,0,1}, {1,1,1,1}, {1,0,0,1}, {1,1,0,1}};
    vector<vector<int> > grid3 = {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    cout << s.islandPerimeter(grid1) << endl;
    cout << s.islandPerimeter(grid2) << endl;
    cout << s.islandPerimeter(grid3) << endl;

    return 0;
}