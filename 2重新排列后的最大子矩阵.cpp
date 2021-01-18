class Solution {
private:
    int len1, len2;
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        len1 = matrix.size(), len2 = matrix[0].size();
        vector<vector<int> >store1 = matrix;
        for(int i = len1 -2; i >= 0; i--){
            for(int j = 0; j < len2; j++){
                if(matrix[i][j] == 1)store1[i][j] = store1[i+1][j] + 1;
            }
        }
        int res = INT_MIN;
        for(int i = 0; i < len1; i++){
            vector<int>store2 = store1[i];
            sort(store2.begin(), store2.end());
            for(int j = 0; j < len2; j++){
                int width = len2 - j;
                res = max(res, store2[j] * width);
            }
        }
        return res;
    }
};
