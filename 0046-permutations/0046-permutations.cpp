class Solution {
public:
    void getpermute(vector<int>& nums,int idx,vector<vector<int>>& ans)
    {
        //Base Case
        if(idx== nums.size()){
            ans.push_back(nums);
            return;
        }
        //Try all choices
        for(int i = idx;i< nums.size();i++)
        {
            //choose
            swap(nums[idx],nums[i]);
            //Recursion
            getpermute(nums,idx+1,ans);
            //Backtrack
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermute(nums,0,ans);
        return ans;   
    }
};