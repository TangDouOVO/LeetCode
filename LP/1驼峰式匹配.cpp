class Solution {
public:
    bool solution(const string& temp1, const string & temp2) {
        int i = 0, j = 0;
        int len1 = temp1.size(),  len2 = temp2.size();
        while(i < len1) {
            if(j < len2 && temp1[i] == temp2[j]) {
                i++;
                j++;
            }else if(isupper(temp1[i])) {
                return false;
            }else{
                i++;
            }
        }
        return i == len1 && j == len2;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for(auto& cha : queries){
            if(solution(cha, pattern))res.push_back(true);
            else{
                res.push_back(false);
            }
        }
        return res;
    }
};
