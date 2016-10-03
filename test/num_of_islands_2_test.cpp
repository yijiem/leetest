//
// Created by Yijie Ma on 10/2/16.
//

#include <gmock/gmock.h>

#include "num_of_islands_2.h"

using namespace std;
using ::testing::ElementsAre;

namespace {
class NumOfIslands2Test : public ::testing::Test {
protected:
    NumOfIslands2Test() {};
    ~NumOfIslands2Test() {};

    void SetUp() {};
    void TearDown() {};

private:
};

TEST_F(NumOfIslands2Test, basic) {
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}};
    Solution so;
    vector<int> res = so.numIslands2(m, n, positions);
    ASSERT_THAT(res, ElementsAre(1, 1, 2, 3));
}

TEST_F(NumOfIslands2Test, empty) {
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {};
    Solution so;
    vector<int> res = so.numIslands2(m, n, positions);
    ASSERT_THAT(res, ElementsAre());
}

TEST_F(NumOfIslands2Test, all_separate) {
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    Solution so;
    vector<int> res = so.numIslands2(m, n, positions);
    ASSERT_THAT(res, ElementsAre(1, 2, 3, 4, 5));
}

TEST_F(NumOfIslands2Test, grow) {
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};
    Solution so;
    vector<int> res = so.numIslands2(m, n, positions);
    ASSERT_THAT(res, ElementsAre(1, 1, 1, 1, 1, 1, 1, 1, 1));
}

TEST_F(NumOfIslands2Test, reverse_grow) {
    int m = 3;
    int n = 3;
    vector<pair<int, int>> positions = {{0, 0}, {2, 2}, {0, 1}, {2, 1}, {0, 2}, {2, 0}, {1, 0}, {1, 2}, {1, 1}};
    Solution so;
    vector<int> res = so.numIslands2(m, n, positions);
    ASSERT_THAT(res, ElementsAre(1, 2, 2, 2, 2, 2, 1, 1, 1));
}
} // namespace
