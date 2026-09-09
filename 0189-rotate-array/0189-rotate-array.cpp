class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k= k%n;
        reverse(nums.begin(),nums.end()); //full array reveverse karo
        reverse(nums.begin(),nums.begin()+k);//first k element reverse karo
        reverse(nums.begin()+k,nums.end());//baki element reverse karo
    }
};