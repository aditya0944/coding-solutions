#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<pair<int, int>> sortedQueries(m);
        for (int i = 0; i < m; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> ans(m);
        vector<int> serverCount(n + 1, 0);
        int uniqueServers = 0;
        int left = 0, right = 0;
        
        for (int i = 0; i < m; ++i) {
            int queryTime = sortedQueries[i].first;
            int originalIndex = sortedQueries[i].second;
            
            int windowStart = queryTime - x;
            int windowEnd = queryTime;
            
            while (right < logs.size() && logs[right][1] <= windowEnd) {
                int serverId = logs[right][0];
                if (serverCount[serverId] == 0) {
                    uniqueServers++;
                }
                serverCount[serverId]++;
                right++;
            }
            
            while (left < logs.size() && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverCount[serverId]--;
                if (serverCount[serverId] == 0) {
                    uniqueServers--;
                }
                left++;
            }
            
            ans[originalIndex] = n - uniqueServers;
        }
        
        return ans;
    }
};
