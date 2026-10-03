class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>>&ans)
    {
        //Base Case
        if(index== nums.size()){
            ans.push_back(nums);
            return;
        }
        //is level par konse no.use ho chuke h
        set<int>used;

        //current positions ke liyes choices
        for(int i= index;i<nums.size();i++){
            //same no. dubara nhi lena
            if(used.count(nums[i])){
                continue;
            }
            //no.ko mark kar do
            used.insert(nums[i]);
            //choose
            swap(nums[index], nums[i]);  
            //next position solve karo
            solve(nums,index+1,ans);
            //backtrack
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};