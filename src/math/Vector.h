//
// Created by Christian Meyer on 9/16/2018.
//

#ifndef RAY_TRACER_VECTOR_H
#define RAY_TRACER_VECTOR_H
#include "Point.h"

namespace cs410 {
    namespace math {
        /* FORWARD DECLARATIONS */
        class Point;

        class Vector {
            Point* coordinates;

            public:

            /* CTORS */
            Vector();
            Vector(const Vector& v);
            explicit Vector(Point &p);
            ~Vector();

            /* FUNCTIONS */
            const float& x() const;

            const float& y() const;

            const float& z() const;

            const float magnitude() const;

            const float dot(const Vector& v) const;

            Vector cross(const Vector& v) const;

            /* OPERATORS */

            Vector& operator=(const Vector& v);
        };

        Vector operator*(const float& f, const Vector& v);
        std::ostream &operator<<(std::ostream& os, const Vector& v);

    }
}


#endif //RAY_TRACER_VECTOR_H
