class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort array
        sort(nums.begin(),nums.end());
        // store ans
        vector<vector<int>>ans;
        //fix one element
        for(int i = 0;i<nums.size();i++){
            //skip duplicates i
            if(i>0&& nums[i]==nums[i-1])
            continue;
            //two pointer
            int j = i+1;
            int k = nums.size()-1;
            //search while j doesnot cross
            while(j<k){
                //calculate sum
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    //move both pointers
                    j++;
                    k--;
                    //skip duplicates j
                    while(j<k&&nums[j]==nums[j-1])
                    j++;
                }
            }
        }
        return ans;
    }
};