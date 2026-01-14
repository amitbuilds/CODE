class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int> &candidates,vector<int> temp,int target,int idx){
        if(target==0){
            ans.push_back(temp);
        }
        for(int i = idx ; i < candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            solve(candidates,temp,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates,temp,target,0);
        return ans;
        // int n = 0;
        // for(int i = 0 ;i<candidates.size();i++){
        //     if(candidates[i]==target){
        //         n = i;
        //         break;
        //     }
        // }
        // for(int i = 0;i<n;i++){
        //     if(candidates[i]==target){
        //         ans.push_back({candidates[i]});
        //     }
        // }
        // for(int i =0 ; i < n ; i++){
        //     for(int j = i+1;j<n;j++){
        //         if((candidates[i]+candidates[j])==target){
        //             ans.push_back({candidates[i],candidates[j]});
        //         }
        //     }
        // }
        // for(int i =0 ; i < n ; i++){
        //     for(int j = i+1;j<n;j++){
        //         for(int k = j+1;k<n;k++){
        //             if((candidates[i]+candidates[j]+candidates[k])==target){
        //                 ans.push_back({candidates[i],candidates[j],candidates[k]});
        //             }
        //         }
        //     }
        // }
        // return ans;

    }
};