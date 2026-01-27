class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int n = aliceSizes.size();
        int m = bobSizes.size();
        int sum1 = 0;
        int sum2 = 0;
        for(int i =0 ; i<n;i++){
            sum1+=aliceSizes[i];
        }
        for(int i = 0;i<m;i++){
            sum2+=bobSizes[i];
        }
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(sum1 - aliceSizes[i] + bobSizes[j] == sum2 - bobSizes[j] + aliceSizes[i]){
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }
        return {};
    }
};