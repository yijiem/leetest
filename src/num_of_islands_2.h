//
// Created by Yijie Ma on 9/29/16.
//

#include <vector>

using namespace std;

namespace {
class Solution {
private:
    vector<int> rank_;
    vector<int> id_;
    int count_ = 0;

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        for (int i = 0; i < m * n; ++i) {
            rank_.push_back(1);
            id_.push_back(-1);
        }

        vector<int> res;
        for (auto p : positions) {
            ++count_;
            id_[p.first * n + p.second] = p.first * n + p.second;
            if (p.first > 0 && id_[(p.first - 1) * n + p.second] != -1) { // top
                union_func(p.first * n + p.second, (p.first - 1) * n + p.second);
            }

            if (p.first < m - 1 && id_[(p.first + 1) * n + p.second] != -1) { // down
                union_func(p.first * n + p.second, (p.first + 1) * n + p.second);
            }

            if (p.second > 0 && id_[p.first * n + p.second - 1] != -1) { // left
                union_func(p.first * n + p.second, p.first * n + p.second - 1);
            }

            if (p.second < n - 1 && id_[p.first * n + p.second + 1] != -1) { // right
                union_func(p.first * n + p.second, p.first * n + p.second + 1);
            }

            res.push_back(count_);
        }

        return res;
    }

    void union_func(int p, int q) {
        int pp = find(p);
        int pq = find(q);

        if (pp == pq) return;
        --count_;
        if (rank_[pp] > rank_[pq]) { // weighted
            rank_[pp] += rank_[pq];
            id_[pq] = pp;
        } else {
            rank_[pq] += rank_[pp];
            id_[pp] = pq;
        }
    }

    int find(int p) {
        while (p != id_[p]) {
            id_[p] = id_[id_[p]]; // path compression
            p = id_[p];
        }

        return p;
    }
};
} // namespace
