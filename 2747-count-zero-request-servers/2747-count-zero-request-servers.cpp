class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin() , logs.end() , [](vector<int>&a , vector<int>&b) {
            return a[1] < b[1];
        });
        vector<pair<int , int>>q;
        for(int i = 0; i< queries.size(); i++) {
            q.push_back({queries[i] , i});
        }
        sort(q.begin() , q.end());
        int active = 0 , l = 0 , r = 0;
        vector<int>cnt(n+1 , 0);
        vector<int>ans(queries.size());

        for(auto& [time , idx] : q) {
            int start = time - x;
            while(r < logs.size() && logs[r][1] <= time) {
                if(cnt[logs[r][0]] == 0) {
                    active++;
                }
                cnt[logs[r][0]]++;
                r++;
            }

            while(l < logs.size() && logs[l][1] < start) {
                cnt[logs[l][0]]--;
                if(cnt[logs[l][0]] == 0) {
                    active--;
                }
                l++;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};