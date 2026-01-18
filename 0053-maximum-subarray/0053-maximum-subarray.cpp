class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxS = INT_MIN;
        for(int val:nums){
            sum+=val;
            maxS = max(sum,maxS);
            if(sum<0){
                sum=0;
            }
        }
    return maxS;
    }
};