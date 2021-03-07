#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int y = grid.size();
        int x = grid[0].size();
        int num_of_one = 0;
        int res = 0;
        deque<pair<int,int>> list_of_two;
        for(int i =0; i<y; i++){
            for(int j=0; j<x; j++){
                if( grid[i][j] == 1) num_of_one++;
                if( grid[i][j] == 2) list_of_two.push_back(make_pair(j,i));
            }
        }
        while(num_of_one > 0){
            int s = list_of_two.size();
            for(int i=0; i<s; i++){
                pair<int,int> tmp = list_of_two[i];
                if(tmp.first > 0 && tmp.first<x-1){
                    if(grid[tmp.second][tmp.first-1] == 1) {
                        grid[tmp.second][tmp.first-1]++;
                        num_of_one--;
                    }
                    if(grid[tmp.second][tmp.first+1] == 1){
                        grid[tmp.second][tmp.first+1]++;
                        num_of_one--;
                    }
                }
                else if( tmp.first == 0 && x>1){
                    if(grid[tmp.second][tmp.first+1] == 1){
                        grid[tmp.second][tmp.first+1]++;
                        num_of_one--;
                    }
                }
                else if( tmp.first == x-1 && x>1){
                    if(grid[tmp.second][tmp.first-1] == 1){
                        grid[tmp.second][tmp.first-1]++;
                        num_of_one--;
                    }
                }
                
                if(tmp.second > 0 && tmp.second<y-1){
                    if(grid[tmp.second-1][tmp.first] == 1) {
                        grid[tmp.second-1][tmp.first]++;
                        num_of_one--;
                    }
                    if(grid[tmp.second+1][tmp.first] == 1){
                        grid[tmp.second+1][tmp.first]++;
                        num_of_one--;
                    }
                }
                else if( tmp.second == 0 && y>1){
                    if(grid[tmp.second+1][tmp.first] == 1){
                        grid[tmp.second+1][tmp.first]++;
                        num_of_one--;
                    }
                }
                else if( tmp.second == y-1 && y>1){
                    if(grid[tmp.second-1][tmp.first] == 1){
                        grid[tmp.second-1][tmp.first]++;
                        num_of_one--;
                    }
                }
            }
            while(list_of_two.empty()!=true) list_of_two.pop_back();
            for(int i =0; i<y; i++){
                for(int j=0; j<x; j++){
                    if( grid[i][j] == 2) list_of_two.push_back(make_pair(j,i));
                }
            }
            if(s == list_of_two.size()) return -1;
            res++;
        }
        return res;
    }
};

int main()
{
    vector<vector<int> > grid = {{2,1,1}, {1,1,0},{0,1,1}};
    vector<vector<int> > grid2 = {{1},{2}};
    vector<vector<int> > grid3 = {{2,1,1}, {0,1,1},{1,0,1}};
    Solution s;
    cout << s.orangesRotting(grid2)<< endl;
    return 0;
}