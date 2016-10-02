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
} // namespace