//
// Created by Yijie Ma on 10/2/16.
//

#include <gmock/gmock.h>

#include "longest_consecutive_sequence.h"

using namespace std;

namespace {
class LongestConsecutiveSequenceTest : public ::testing::Test {
protected:
    LongestConsecutiveSequenceTest() {};

    ~LongestConsecutiveSequenceTest() {};

    void SetUp() {};

    void TearDown() {};

private:
};

TEST_F(LongestConsecutiveSequenceTest, basic) {
    vector<int> nums = {100, 4, 200, 1, 2, 3};
    Solution so;
    EXPECT_EQ(so.longestConsecutive(nums), 4);
}

TEST_F(LongestConsecutiveSequenceTest, all_one) {
    vector<int> nums = {1, 1, 1, 1, 1, 1};
    Solution so;
    EXPECT_EQ(so.longestConsecutive(nums), 1);
}

TEST_F(LongestConsecutiveSequenceTest, separate) {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    Solution so;
    EXPECT_EQ(so.longestConsecutive(nums), 1);
}

TEST_F(LongestConsecutiveSequenceTest, consecutive) {
    vector<int> nums = {7, 6, 5, 4, 3, 2, 1};
    Solution so;
    EXPECT_EQ(so.longestConsecutive(nums), 7);
}

TEST_F(LongestConsecutiveSequenceTest, error) {
    vector<int> nums = {9, 1, -3, 2, 4, 8, 3, -1, 6, -2, -4, 7};
    Solution so;
    EXPECT_EQ(so.longestConsecutive(nums), 4);
}
} // namespace