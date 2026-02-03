class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return false;
        int i = 0;
        while(i+1<n && nums[i]<nums[i+1]){
            i++;
        }
        if(i==0 || i==n-1){
            return false;
        }
        int j = i;
        while(j+1<n && nums[j]>nums[j+1]){
            j++;
        }
        if(j==i||j==n-1){
            return false;
        }
        int k = j;
        while(k+1<n &&nums[k]<nums[k+1]){
            k++;
        }
        return k==n-1;
        // int mini = INT_MAX;
        // int maxi = INT_MIN;
        // int p = 0;
        // int q = 0 ;
        // int n = nums.size();
        // bool found = false;
        // for(int i =0 ;i<n;i++){
        //     if(nums[i]>nums[i+1] && i<n){
        //         p = i;
        //         found = true;
        //     }
        //     else{
        //         found = false;
        //     }
        // }
        // for(int i = p;i<n;i++){
        //     if(nums[i]<nums[i+1] && i<n){
        //         q = i;
        //         found = true;
        //     }else{
        //         found = false;
        //     }
        // }
        // for(int i = q;i<n;i++){
        //     if(nums[i]<nums[i+1] && i<n){
        //         found = true;
        //     }else{
        //         found = false;
        //     }
        // }
        // return found;
    }
};