class Solution {
private:
    int len1, len2;
    vector<vector<int> >direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    bool dfs(vector<vector<int> >&grid, vector<vector<bool> >&visit, int x, int y, int res){
        if(x == len1 - 1 && y == len2 - 1){
            return true;
        }
        visit[x][y] = true;
        for(auto cha : direct){
            int temp1 = x + cha[0];
            int temp2 = y + cha[1];
            if(temp1 >= 0 && temp1 < len1 && temp2 >= 0 && temp2 < len2 && visit[temp1][temp2] == false && grid[temp1][temp2] < res && grid[x][y] < res){
                if(dfs(grid, visit, temp1, temp2, res))return true;//所有可能路径，不需要回溯
            }
        }
        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        //二分查找+深度优先搜索
        len1 = grid.size(), len2 = grid[0].size();
        int left = 0, right = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            vector<vector<bool> >visit(len1, vector<bool>(len2, false));
            if(!dfs(grid, visit, 0, 0, mid)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left-1;
    }
};
