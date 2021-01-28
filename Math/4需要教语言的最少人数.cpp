class Solution {
public:
    //判断两个人之间是否有共同语言
    bool solution(vector<vector<int> >&language, int i, int j){
        vector<int>temp1 = language[i-1];
        vector<int>temp2 = language[j-1];
        for(auto cha1 : temp1){
            for(auto cha2 : temp2){
                if(cha1 == cha2)return true;
            }
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        map<int, int>store1;
        map<int, int>store2;
        //记录每个人在自己的好友名单中，没有共同语言的好友人数
        for(int i = 0; i < friendships.size(); i++){
            if(!solution(languages, friendships[i][0], friendships[i][1])){
                store1[friendships[i][0]]++;
                store1[friendships[i][1]]++;
            }
        }
        //统计store1中所有人会的语言和语言数
        for (auto p: store1) {
            for (auto language: languages[p.first-1]) {
                store2[language]++;
            }
        }
        //找到最通用的语言
        int store = 0;
        for(auto cha : store2){
            store = max(store, cha.second);
        }

        return store1.size() - store;
    }
};
