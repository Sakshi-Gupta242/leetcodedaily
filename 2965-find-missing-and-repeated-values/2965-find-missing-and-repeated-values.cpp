class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n = arr.size();

        vector<int> freq(n*n + 1,0);

        for(int i = 0;i<n; i++){
            for(int j = 0;j<n;j++){
                freq[arr[i][j]]++;
            }
        }
        int repeating = -1;
        int missing =-1;

        for(int i = 1;i<=n*n;i++){
            if(freq[i] ==2){
                repeating = i;
            }
            if(freq[i] == 0){
                missing = i;
            }
        }
        return {repeating,missing};

    }
};