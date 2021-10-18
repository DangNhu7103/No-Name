#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
    public:
        float X, Y;

    public:
        Vector(float x = 0, float y = 0): X(x), Y(y) {}

    public:

        // Operator +
        inline Vector operator+ (const Vector& v2) const {
            return Vector(X + v2.X, Y + v2.Y);
        }

        // Operator -
        inline Vector operator- (const Vector& v2) const {
            return Vector(X - v2.X, Y - v2.Y);
        }

        // Operator *
        inline Vector operator* (const float multi) const {
            return Vector(X*multi, Y*multi);
        }

        void Log(std::string nameV) {
            std::cout << nameV << ": " << X << " " << Y << std::endl;
        }
};

#endif // VECTOR_H
