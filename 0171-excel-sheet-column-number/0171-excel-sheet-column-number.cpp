class Solution {
public:
    int titleToNumber(string columnTitle) {
        // vector<int> ans;
        int sum = 0;
        for(int ch : columnTitle){
            int temp = ch - 'A' + 1;
            sum = sum * 26 + temp;
        }
        // for(int i = 0 ; i< ans.size();i++){
        //     sum = sum + ans[i];
        // }
        return sum ;

    }
};