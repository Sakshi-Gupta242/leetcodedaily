class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> A) {
        
        sort(A.begin(),A.end());

        int minDiff =INT_MAX;

        for(int i =1;i<A.size();i++){
            minDiff = min(minDiff,A[i] - A[i-1]);
        }
        vector<vector<int>>ans;

       for(int i =1;i<A.size();i++){
        if (A[i] - A[i-1] == minDiff){
            ans.push_back({A[i-1],A[i]});
        }
       }
       return ans;
    }
};