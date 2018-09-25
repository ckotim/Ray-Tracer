//
// Created by Christian Meyer on 9/16/2018.
//

#include <cmath>
#include "Vector.h"

namespace cs410 {
    namespace math {

        /* CTORS */
        Vector::Vector() : coordinates(new Point()) {}

        Vector::Vector(const Vector &v) { coordinates = new Point(*v.coordinates); }

        Vector::Vector(Point &p) : coordinates(&p) {}

        Vector::~Vector() { delete coordinates; }

        /* FUNCTIONS */
        const float& Vector::x() const { return coordinates->x(); }

        const float& Vector::y() const { return coordinates->y(); }

        const float& Vector::z() const { return coordinates->z(); }

        const float Vector::magnitude() const {
            return (float)std::sqrt(std::pow(coordinates->x(), 2) + std::pow(coordinates->y(), 2) + std::pow(coordinates->z(),2));
        }


        /* OPERATORS */

        // Assignment
        Vector& Vector::operator=(const Vector &v) {
            delete coordinates;
            *coordinates = *v.coordinates;
            return *this;
        }

        // Dot Product
        const float Vector::dot(const Vector& v) const {
            return (x() * v.x()) + (y() * v.y()) + (z() * v.z());
        }

        // Cross Product
        Vector Vector::cross(const Vector &v) const {
            float x = (this->y() * v.z()) - (this->z() * v.y());
            float y = (this->z() * v.x()) - (this->x() * v.z());
            float z = (this->x() * v.y()) - (this->y() * v.x());
            return Vector(*new Point(x,y,z));
        }

        // Vector Scaling
        Vector operator*(const float& f, const Vector& v) {
            return Vector(*new Point(f * v.x(), f * v.y(), f * v.z()));
        }

        // cout << Point
        std::ostream &operator<<(std::ostream &os, const Vector &v) {
            os << "<" << v.x() << "," << v.y() << "," << v.z() << ">";
            return os;
        }

    }
}
