class Solution {
public:
    int characterReplacement(string s, int k) {
        //滑动窗口
        vector<int>store(26, 0);
        int len = s.size();
        int max_num = 0;
        int left = 0;
        int res = 0;
        for(int right = 0; right < len; right++){
            store[s[right] - 'A']++;
            max_num = max(max_num, store[s[right] - 'A']);
            //缩小窗口
            if(right - left + 1 - max_num > k){
                store[s[left] - 'A']--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
