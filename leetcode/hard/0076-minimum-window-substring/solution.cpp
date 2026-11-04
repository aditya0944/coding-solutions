#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        
        int counter = t.size();
        int begin = 0, end = 0;
        int head = 0;
        int len = INT_MAX;
        
        while (end < s.size()) {
            if (map[s[end]] > 0) {
                counter--;
            }
            map[s[end]]--;
            end++;
            
            while (counter == 0) {
                if (end - begin < len) {
                    len = end - begin;
                    head = begin;
                }
                
                map[s[begin]]++;
                if (map[s[begin]] > 0) {
                    counter++;
                }
                begin++;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(head, len);
    }
};
