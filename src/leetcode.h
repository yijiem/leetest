//
// Created by Yijie Ma on 9/30/16.
//
#pragma once

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

using namespace std;
using ::testing::ElementsAre;

namespace {

class Leetcode : public ::testing::Test {
protected:
    Leetcode() {}
    ~Leetcode() {}

    void SetUp() {}
    void TearDown() {}

private:
};
} // namespace