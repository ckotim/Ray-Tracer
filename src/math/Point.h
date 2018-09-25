//
// Created by Christian Meyer on 9/16/2018.
//

#ifndef RAY_TRACER_POINT_H
#define RAY_TRACER_POINT_H

#include <iostream>
#include "Vector.h"

namespace cs410 {
    namespace math {
        /* FORWARD DECLARATIONS */
        class Vector;

        class Point {
            float xval, yval, zval, hval;


        public:

            /* CTORS */
            Point();

            Point(float x, float y, float z);

            /* FUNCTIONS */
            const float& x() const;

            const float& y() const;

            const float& z() const;

            /* OPERATORS */

            // Point - Point = Vector
            Vector operator-(const Point& p) const;

            //Point + Vector = V
            Point operator+(const Vector& v) const;

            // Point == Point
            bool operator==(const Point& p) const;

            // Point != Point
        };

        std::ostream &operator<<(std::ostream& os, const Point& p);
    }
}

#endif //RAY_TRACER_POINT_H
