//
// Created by Christian Meyer on 9/20/2018.
//

#ifndef RAY_TRACER_TRANSFORMATION_H
#define RAY_TRACER_TRANSFORMATION_H

namespace cs410 {
    class Transformation {
    public:
        // ctors
        Transformation(float wx, float wy, float wz, float theta, float scale, float tx, float ty, float tz,
                       std::string obj);

        // methods
        math::Matrix get_rotation_matrix() const;

        math::Matrix get_scale_matrix() const;

        math::Matrix get_translate_matrix() const;

        float wx, wy, wz, theta, scale, tx, ty, tz;
        std::string obj;
    private:
    };
}

#endif //RAY_TRACER_TRANSFORMATION_H
