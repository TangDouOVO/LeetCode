class Solution {
public:
    vector<int>count(string x){
        vector<int>res(2, 0);
        for(auto cha : x){
            res[cha - '0']++;
        }
        return res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //0-1背包问题
        //这里的子集个数等价于能有多少个字符串被包含在内
        //dp[i][j][k]前i个元素中最多有j个0和n个1的子集个数
        int len = strs.size();
        vector<vector<vector<int> > >dp(len+1, vector<vector<int> >(m+1, vector<int>(n+1, 0)));
        for(int i = 1; i <= len; i++){
            //计算当前字符串中0和1的个数
            vector<int>store = count(strs[i-1]);
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    if(store[0] > j || store[1] > k){
                        dp[i][j][k] = dp[i-1][j][k];
                    }else{
                        //装和不装两者选最大的
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - store[0]][k - store[1]] + 1);
                    }

                }
            }
        }
        return dp[len][m][n];
    }
};
