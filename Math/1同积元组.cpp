class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>store;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                int temp = nums[i] * nums[j];
                store[temp]++;
            }
        }
        int res = 0;
        for(auto cha : store){
            res += cha.second * (cha.second - 1) / 2;//排列组合
        }
        //8 = 2 * 2 * 2表示其中一个二元组内部排序 * 另一个二元组内部排序 * 两个二元组整体排序
        return res * 8;
    }
};
