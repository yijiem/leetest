//
// Created by Yijie Ma on 10/9/16.
//

#include <gmock/gmock.h>

#include "quicksort_3way.h"

using ::testing::ElementsAreArray;

namespace {
class QuickSort3WayTest : public ::testing::Test {
public:
    QuickSort3WayTest() {}

    ~QuickSort3WayTest() {}

    void SetUp() {}

    void TearDown() {}
};

TEST_F(QuickSort3WayTest, basic) {
    std::vector<int> array = {4, 9, 1, 5, 2, 3, 5, 4, 7, 0, 6};
    QuickSort3Way<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({0, 1, 2, 3, 4, 4, 5, 5, 6, 7, 9}));
}

TEST_F(QuickSort3WayTest, same) {
    std::vector<int> array = {1, 1, 1, 1, 1, 1, 1};
    QuickSort3Way<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({1, 1, 1, 1, 1, 1, 1}));
}

TEST_F(QuickSort3WayTest, multiple_duplicate) {
    std::vector<int> array = {1, 0, 1, 0, 1, 0, 1, 0};
    QuickSort3Way<int>::sort(array);
    ASSERT_THAT(array, ElementsAreArray({0, 0, 0, 0, 1, 1, 1, 1}));
}
} // namespace