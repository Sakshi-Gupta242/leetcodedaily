class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        //sorted arr me target dhundho
        for(int i = 0;i<nums.size();i++){
        if(nums[i]==target){
            ans.push_back(i);
        }
     }
     return ans;
    }
};