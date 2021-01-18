class Solution {
private:
    int mode = 1e9+7;
    vector<vector<int> >number;
public:
    //计算以i, j为左上角顶点;m,n为右下角顶点的矩形中是否有A
    bool Has_A(int i, int j, int m, int n){
        int temp1 = 0, temp2 = 0, temp3 = 0;
        if(i-1 >= 0)temp1 = number[i-1][n];
        if(j-1 >= 0)temp2 = number[m][j-1];
        if(i-1 >= 0 && j-1 >= 0)temp3 = number[i-1][j-1];
        return number[m][n] - (temp1 + temp2 - temp3) > 0;
    }
    int ways(vector<string>& pizza, int k) {
        int len1 = pizza.size(), len2 = pizza[0].size();
        //number[i][j]记录以(i,j)为底的pizza中有多少个苹果
        number = vector<vector<int> >(len1, vector<int>(len2, 0));
        if(pizza[0][0] == 'A')number[0][0] = 1;
        for(int i = 1; i < len1; i++){
            number[i][0] = number[i-1][0] + (pizza[i][0] == 'A'); 
        }
        for(int j = 1; j < len2; j++){
            number[0][j] = number[0][j-1] + (pizza[0][j] == 'A');
        }
        for(int i = 1; i < len1; i++){
            for(int j = 1; j < len2; j++){
                number[i][j] = number[i-1][j] + number[i][j-1] - number[i-1][j-1] + (pizza[i][j] == 'A');
            }
        }
        //dp[i][j][k]i,j表示披萨剩余部分的左上角,k表示当前披萨被切成k块
        vector<vector<vector<int> > >dp(len1, vector<vector<int> >(len2, vector<int>(k+1, 0)));
        //初始化
        dp[0][0][1] = 1;
        for(int m = 2; m <= k; m++){
            for(int i = 0; i < len1; i++){
                for(int j = 0; j < len2; j++){
                    if(dp[i][j][m-1] == 0)continue;
                    //穷举水平切
                    for(int z = i+1; z < len1; z++){
                        if(Has_A(i, j, z-1, len2-1) && Has_A(z, j, len1-1, len2-1)){
                            dp[z][j][m] += dp[i][j][m-1];
                            dp[z][j][m] %= mode;
                        }
                    }
                    //穷举垂直切
                    for(int z = j + 1; z < len2; z++){
                        if(Has_A(i, j, len1-1, z - 1) && Has_A(i, z, len1-1, len2-1)){
                            dp[i][z][m] += dp[i][j][m-1];
                            dp[i][z][m] %= mode;
                        }
                    }
                }
            }
        }
        long long res = 0;
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                res += dp[i][j][k];
            }
            res %= mode;
        }
        return res;
    }
};
