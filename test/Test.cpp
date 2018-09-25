//
// Created by Christian Meyer on 9/17/2018.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/math/Point.h"

typedef cs410::math::Point Point;
typedef cs410::math::Vector Vector;

TEST(PointTests, DefaultCTOR) {
    Point point = Point();
    EXPECT_EQ(0, point.x());
    EXPECT_EQ(0, point.y());
    EXPECT_EQ(0, point.z());
}

TEST(PointTests, XYZCTOR) {
    Point point = Point(1, 2, 3);
    EXPECT_EQ(1, point.x());
    EXPECT_EQ(2, point.y());
    EXPECT_EQ(3, point.z());
}

TEST(PointTests, CopyCTOR) {
    Point point = Point(Point(100, -2, 3.5));
    EXPECT_EQ(100, point.x());
    EXPECT_EQ(-2, point.y());
    EXPECT_EQ(3.5, point.z());
}








