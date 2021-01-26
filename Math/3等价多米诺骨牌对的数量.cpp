class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int res = 0;
        map<pair<int, int>, int>store;
        int len = dominoes.size();
        for(int i = 0; i < len; i++){
            if(dominoes[i][0] < dominoes[i][1]){
                store[make_pair(dominoes[i][0], dominoes[i][1])]++;
            }else{
                store[make_pair(dominoes[i][1], dominoes[i][0])]++;
            } 
        }
        for(auto cha : store){
            res += cha.second *(cha.second-1) / 2;
        }
        return res;
    }
};
