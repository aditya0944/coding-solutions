#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        int mx = *std::max_element(nums.begin(), nums.end());
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return mx * nums.size() - sum;
    }
};
