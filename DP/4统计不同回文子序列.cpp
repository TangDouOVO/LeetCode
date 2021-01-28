class Solution {
private:
    const int mode = 1e9+7;
public:
    int countPalindromicSubsequences(string S) {
        int len = S.size();
        vector<vector<int> >dp(len, vector<int>(len, 0));
        //dp[i][j]表示下标i到j区间内的回文字符串个数（包括两端）
        //初始化
        for(int i = 0; i < len; i++){
            dp[i][i] = 1;
        }
        //动态规划
        for(int k= 2; k <= len; k++){
            for(int i = 0; i < len - k + 1; i++){
                int j = i + k - 1;
                if(S[i] != S[j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }else{
                    dp[i][j] = dp[i + 1][j - 1] * 2;
                    int l = i + 1, r = j - 1;
                    while (l <= r && S[l] != S[i]) l += 1;
                    while (l <= r && S[r] != S[i]) r -= 1;
                    if (l > r) dp[i][j] += 2;
                    else if (l == r) dp[i][j] += 1;
                    else dp[i][j] -= dp[l + 1][r - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mode : dp[i][j] % mode;
            }
        }
        return dp[0][len-1];
    }
};
