class Solution {
public:
static bool compare(vector<int>& p1,vector<int>& p2){
    return p1[1] < p2[1];
}
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(pairs.begin(),pairs.end(),compare);

        int count = 0;
        int lastEnd = INT_MIN;

        for(int i =0;i<pairs.size();i++){
            if(pairs[i][0]>lastEnd){
                count++;
                lastEnd = pairs[i][1];

            }
        }
        return count;      
    }
};