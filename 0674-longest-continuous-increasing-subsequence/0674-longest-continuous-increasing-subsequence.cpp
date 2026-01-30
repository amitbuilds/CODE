class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int currentLen =1;
        int maxLen = 1;
        for(int i=0; i<n - 1;i++) {
            if(nums[i+1]>nums[i]) {
                currentLen++; 
            }else{
                currentLen= 1; 
            }
            maxLen = max(maxLen,currentLen);
        }

        return maxLen;
        
        // vector<int> arr;
        // int n = nums.size();
        // int sum = 1;
        // for(int i=0;i<n-1;i++){
        //     if(nums[i]<nums[i+1] && i<n){
        //         sum++;
        //     }
        // }
        // return sum ;

        // for(int i =0 ;i<n;i++){
        //     arr.push_back(nums[i]);
        // }
        // int sum = 0;
        // sort(arr.begin(),arr.end());
        // for(int i=0;i<n;i++){
        //     if(arr[i]!=nums[i]){
        //         sum++;
        //     }
        // }
        // return (sum+1);

    }
};