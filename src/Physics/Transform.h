#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vector.h"
#include <iostream>

class Transform {
    public:
        float X, Y;

    public:
        Transform(float x = 0, float y = 0): X(x), Y(y) {}

        void Log(std::string nameT) {
            std::cout << nameT << ": " << X << " " << Y << std::endl;
        }

    private:
        inline void TransformX(float x) {X += x;}
        inline void TransformY(float y) {Y += y;}
        inline void Translate(Vector v) {X += v.X; Y += v.Y;}


};

#endif // TRANSFORM_H
