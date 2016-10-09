//
// Created by Yijie Ma on 10/8/16.
//

#include <gmock/gmock.h>

#include "mergesort_bu.h"

using ::testing::ElementsAreArray;

namespace {
class MergeSortBUTest : public ::testing::Test {
public:
    MergeSortBUTest() {}

    ~MergeSortBUTest() {}

    void SetUp() {};

    void TearDown() {};
};

TEST_F(MergeSortBUTest, basic) {
    std::vector<int> array = {4, 9, 1, 5, 2, 3, 5, 4, 7, 0, 6};
    MergeSortBU<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({0, 1, 2, 3, 4, 4, 5, 5, 6, 7, 9}));
}

TEST_F(MergeSortBUTest, same) {
    std::vector<int> array = {1, 1, 1, 1, 1, 1, 1};
    MergeSortBU<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({1, 1, 1, 1, 1, 1, 1}));
}

TEST_F(MergeSortBUTest, multiple_duplicate) {
    std::vector<int> array = {1, 0, 1, 0, 1, 0, 1, 0};
    MergeSortBU<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({0, 0, 0, 0, 1, 1, 1, 1}));
}
} // namespace