class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i<nums.size();i++){
            
            int num = nums[i];
            int sum = 0;
            //Digit sum nikalna
            while(num>0){
                sum+=num % 10;
                num= num /10;
            }

            //digit sum == index?
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};