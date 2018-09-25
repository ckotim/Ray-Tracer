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
    Point point1 = Point();
    Point point2 = Point(100, -2, 3.5);
    EXPECT_FALSE(point1 == point2);
    point1 = Point(point2);
    EXPECT_TRUE(point1 == point2);
}

TEST(PointTests, AssignmentOperator) {
    Point point1 = Point();
    Point point2 = Point(100, -2, 3.5);
    EXPECT_FALSE(point1 == point2);
    point1 = point2;
    EXPECT_TRUE(point1 == point2);
}

TEST(VectorTests, DefaultCTOR) {
    Vector vector = Vector();
    EXPECT_EQ(0, vector.x());
    EXPECT_EQ(0, vector.y());
    EXPECT_EQ(0, vector.z());
}

TEST(VectorTests, XYZCTOR) {
    Vector vector = Vector(1,-2,3.5);
    EXPECT_EQ(1, vector.x());
    EXPECT_EQ(-2, vector.y());
    EXPECT_EQ(3.5, vector.z());
}

TEST(VectorTests, PointCTOR) {
    Vector vector = Vector(*new Point(1,-2,3.5));
    EXPECT_EQ(1, vector.x());
    EXPECT_EQ(-2, vector.y());
    EXPECT_EQ(3.5, vector.z());
}

TEST(VectorTests, CopyCTOR) {
    Vector vector1 = Vector();
    Vector vector2 = Vector(1,2,3);
    EXPECT_FALSE(vector1 == vector2);
    vector1 = Vector(vector2);
    EXPECT_TRUE(vector1 == vector2);
}

TEST(VectorTests, AssignmentOperator) {
    Vector vector1 = Vector();
    Vector vector2 = Vector(1,2,3);
    EXPECT_FALSE(vector1 == vector2);
    vector1 = vector2;
    EXPECT_TRUE(vector1 == vector2);
}

TEST(VectorTests, Magnitude) {
    Vector vector = Vector(-3,0,4);
    EXPECT_EQ(5, vector.magnitude());
}

TEST(VectorTests, DotProduct) {
    Vector vector1 = Vector(1,2,3);
    Vector vector2 = Vector(1,5,7);
    EXPECT_EQ(32, vector1.dot(vector2));
}

TEST(VectorTests, CrossProduct) {
    Vector vector1 = Vector(1,2,3);
    Vector vector2 = Vector(3,2,1);
    Vector result = Vector(-4,8,-4);
    EXPECT_EQ(result, vector1.cross(vector2));
}

TEST(OperatorTests, PointMinusPoint) {
    Point point1 = Point(1,2,3);
    Point point2 = Point(1,1,-1);
    Vector result = Vector(0,1,4);
    EXPECT_EQ(result, point1 - point2);
}

TEST(OperatorTests, PointPlusVector) {
    Point point = Point(1,2,3);
    Vector vector = Vector(-10,100,0);
    Point result = Point(-9,102,3);
    EXPECT_EQ(result, point + vector);
}

TEST(OperatorTests, VectorScale) {
    Vector vector = Vector(-1,0,2);
    Vector result = Vector(-5,0,10);
    EXPECT_EQ(result, 5 * vector);
}











