class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = INT_MIN;
        int len = arr.size();
        if(len == 1)return 1;
        vector<vector<int> >dp(len, vector<int>(2, 1));
        //初始化
        //dp[i][1]以i结尾的且大于前一个数满足湍流子数组的长度
        //dp[i][0]以i结尾的且小于前一个数满足湍流子数组的长度
        for(int i = 1; i < len; i++){
            if(arr[i-1] < arr[i]){
                dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
            }else if(arr[i-1] > arr[i]){
                dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
            }
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};
