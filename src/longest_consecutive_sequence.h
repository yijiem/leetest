//
// Created by Yijie Ma on 10/1/16.
//

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:
    std::unordered_set<int> iterate_set_;
    std::unordered_set<int> kick_out_set_;
public:
    int longestConsecutive(vector<int>& nums) {
        for (int i : nums) {
            iterate_set_.insert(i);
            kick_out_set_.insert(i);
        }

        int res = 0;
        for (auto num : iterate_set_) {
            if (kick_out_set_.find(num) != kick_out_set_.end()) {
                int before_size = kick_out_set_.size();
                int kick_out_size = search(num);
                res = std::max(res, kick_out_size);
                if (kick_out_size > before_size / 2) break;
            }
        }

        return res;
    }

    int search(int num) { // search and kick out in kick_out_set_
        int length = 0;
        int count = 0;
        do {
            if (kick_out_set_.erase(num + count)) ++length;
            if (kick_out_set_.erase(num - count)) ++length;
            ++count;
        } while (kick_out_set_.find(num + count) != kick_out_set_.end() ||
                 kick_out_set_.find(num - count) != kick_out_set_.end());

        return length;
    }
};
