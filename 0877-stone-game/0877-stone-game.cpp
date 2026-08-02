class Solution {
public:
    bool stoneGame(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int alice = 0, bob = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                alice += nums[i];
            else
                bob += nums[i];
        }

        return alice > bob;
    }
};