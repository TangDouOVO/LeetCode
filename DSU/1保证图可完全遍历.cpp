class Solution {
private:
    vector<int>father1;
    vector<int>father2;
public:
    int find_root(int x, vector<int>& par){
        int root = x;
        while(par[root]!=root){
            root = par[root];
        }
        while(par[x]!=root){
            int tmp = par[x];
            par[x] = root;
            x = tmp;
        }
        return root;
    }

    bool merge(int x, int y, vector<int>& father){
        int temp1 = find_root(x, father);
        int temp2 = find_root(y, father);
        if(temp1 != temp2){
            father[temp1] = temp2;
            return true; 
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //并查集
        //初始化father
        father1 = vector<int>(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            father1[i] = i;
        }
        int res = 0;
        int node1_nums = 1;
        //先合并第三种边
        for(auto cha : edges){
            if(cha[0] == 3){
                if(!merge(cha[1], cha[2], father1)){
                    //没有合并
                    res++;
                }else{
                    //合并了
                    node1_nums++;
                }
            }
        }
        father2 = father1;
        int node2_nums = node1_nums;
        //合并前两种边
        for(auto cha : edges){
            if(cha[0] == 1){
                if(!merge(cha[1], cha[2], father1)){
                    //没有合并
                    res++;
                }else{
                    node1_nums++;
                }
            }else if(cha[0] == 2){
                if(!merge(cha[1], cha[2], father2)){
                    res++;
                }else{
                    node2_nums++;
                }
            }
        }
        if(node1_nums != n || node2_nums != n)return -1;
        return res;
    }
};
