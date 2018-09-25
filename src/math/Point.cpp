//
// Created by Christian Meyer on 9/16/2018.
//

#include "Point.h"

namespace cs410 {
    namespace math {

        /* CTORS */
        Point::Point() : Point(0, 0, 0) {}

        Point::Point(float x, float y, float z) : xval(x), yval(y), zval(z), hval(1) {}

        /* FUNCTIONS */
        const float& Point::x() const { return xval; }

        const float& Point::y() const { return yval; }

        const float& Point::z() const { return zval; }

        /* OPERATORS */
        // Point - Point = Vector
        Vector Point::operator-(const Point &p) const {
            return Vector(*new Point(xval - p.xval, yval - p.yval, zval - p.zval));
        }

        // Point + Vector = Point
        Point Point::operator+(const Vector &v) const {
            return {xval + v.x(), yval + v.y(), zval + v.z()};
        }

        // cout << Point
        std::ostream &operator<<(std::ostream &os, const Point &p) {
            os << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
            return os;
        }
    }
}