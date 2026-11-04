#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        int p1 = 0, p2 = 0;
        int current = 0, previous = 0;
        
        for (int i = 0; i <= total / 2; ++i) {
            previous = current;
            
            if (p1 < m && (p2 >= n || nums1[p1] <= nums2[p2])) {
                current = nums1[p1++];
            } else {
                current = nums2[p2++];
            }
        }
        
        if (total % 2 == 0) {
            return (previous + current) / 2.0;
        } else {
            return current;
        }
    }
};
