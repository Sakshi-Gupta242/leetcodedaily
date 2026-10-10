class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        //step1-total operation
        long long k= (long long) k1 + k2; //Operations ko jod diya
        //step2-difference ki frequency
        vector<int>freq(100001,0);

        for(int i =0;i<nums1.size();i++){
            int diff = abs(nums1[i]-nums2[i]); //Difference nikala
            freq[diff]++; //frequency ka Count store kiya
        }
        //step 3- Bade difference ko kam karo
        for(int diff = 100000;diff>0 && k> 0;diff--){
            long long take = min((long long)freq[diff],k);

            freq[diff] -= take;
            freq[diff - 1]+= take;
            k-= take;
        }
        // step 4 square ka sum
        long long ans =0;

        for(int diff = 1;diff<= 100000;diff++){
            ans+= 1LL*diff*diff*freq[diff];
        }
        return ans;
    }
};
//"Sabse bade difference se start karna hai, kyunki bade gap ko kam karne se sabse zyada benefit milta hai."