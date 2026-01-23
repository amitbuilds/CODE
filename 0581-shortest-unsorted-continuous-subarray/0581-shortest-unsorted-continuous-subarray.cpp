class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1,right = -1;
        int maxSeen = nums[0];
        int minSeen = nums[n-1];
        for(int i = 1;i<n;i++){
            if(nums[i]<maxSeen){
                right = i;
            }else{
                maxSeen = nums[i];
            }
        }
         for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSeen)
                left = i;
            else
                minSeen = nums[i];
        }

        if (left == -1) return 0;
        return right - left + 1;
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0;i<n;i++){
        //     int minIdx = i;
        //     for(int j=i+1;j<n;j++){
        //         if(nums[j]<nums[minIdx]){
        //             minIdx = j;
        //             ans++;
        //         }
        //     }
        //     swap(nums[minIdx],nums[i]);
        // }
        // if(ans!=0){
        //     ans = n - ans;
        // }
        // return ans;
    }
};