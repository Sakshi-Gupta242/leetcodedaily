class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int end = 0;

        for (int i = 0; i< weights.size();i++){
            start = max(start,weights[i]);
            end += weights[i];
        }
        int ans = end;
        while (start<= end){
            int mid = start +(end - start)/2;

        int currentWeight = 0;
        int day = 1;
        for(int i = 0; i< weights.size(); i++){
            currentWeight += weights[i];

            if(currentWeight > mid){
                day++;
                currentWeight = weights[i];
        }
      }
      if(day <= days){
        ans = mid;
        end = mid -1;
      }
      else{
        start = mid +1;
      }
    }
    return ans;
  }
};