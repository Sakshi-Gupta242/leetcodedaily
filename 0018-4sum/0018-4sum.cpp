class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n = nums.size();
        //sort
        sort(nums.begin(),nums.end());

        //fix first number
        for(int i = 0;i<n-3;i++){
            //skips duplicate i
            if(i>0 && nums[i]==nums[i-1])continue;

            //fix 2 no.
            for(int j= i+1;j<n-2;j++){
                //skips duplicate j
                if(j>i+1 && nums[j]==nums[j-1])continue;
                //2 pointer
                int p = j+1; int q= n-1;
                //search
                while(p<q){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                    //sum is smaller
                    if(sum<target){
                        p++;
                    }
                    //sum is larger
                    else if(sum>target){
                        q--;
                    }
                    //sum is target
                    else{
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        p++;q--;
                        //skips duplicate q
                        while(p<q && nums[p]== nums[p-1])p++;
                    }
                }
            }
        }
        return ans;
    }
};