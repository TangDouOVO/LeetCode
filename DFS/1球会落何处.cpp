class Solution {
private:
    int len1, len2;
    vector<int>res;
public:
    int dfs(int x, int y, vector<vector<int> >&grid){
        if(x == len1)return y;
        if(grid[x][y] == 1){
            if(y+1 < len2 && grid[x][y+1] == 1){
                return dfs(x+1, y+1, grid);
            }
        }else if(grid[x][y] == -1){
            if(y-1 >= 0 && grid[x][y-1] == -1){
                return dfs(x+1, y-1, grid);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        len1 = grid.size(), len2 = grid[0].size();
        res = vector<int>(len2, -1);
        for(int i = 0 ; i < len2; i++){
            res[i] = dfs(0, i, grid);
        }
        return res;
    }
};
