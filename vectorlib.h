#ifndef VECTORLIB_H
#define VECTORLIB_H

#include <iostream>
#include <cmath>

class Vec2D {
    public:
        float x, y;
        Vec2D(float newX = 0.0f, float newY = 0.0f) : x(newX), y(newY) {}

        float length() {
            return sqrt(x*x + y*y);
        }
        Vec2D normalized() {
            return Vec2D(x / length(), y / length());
        }
        void makeAngle(const double rad) {
            x = std::cos(rad);
            y = std::sin(rad);
        }
        Vec2D getAngleTo(Vec2D &other) {
            return (operator-(other).normalized());
        }
        
        Vec2D operator+(Vec2D const &secondVec) const {
            return Vec2D(x + secondVec.x, y + secondVec.y);
        }
        Vec2D operator-(Vec2D const &secondVec) const {
            return Vec2D(x - secondVec.x, y - secondVec.y);
        }
        Vec2D operator*(float const &mult) const {
            return Vec2D(x * mult, y * mult);
        }
        Vec2D operator/(float const &div) const {
            return Vec2D(x / div, y / div);
        }
        void operator+=(Vec2D const &secondVec) {
            *this = operator+(secondVec);
        }
        void operator-=(Vec2D const &secondVec) {
            *this = operator-(secondVec);
        }
        void operator*=(float const &mult) {
            *this = operator*(mult);
        }
        void operator/=(float const &div) {
            *this = operator/(div);
        }
        bool operator==(Vec2D const &secondVec) {
            return x == secondVec.x && y == secondVec.y;
        }
        bool operator!=(Vec2D const &secondVec) {
            return operator==(secondVec);
        }
};

void debugPrint(Vec2D const &vec) {
    std::cout << "X is: " << vec.x << " Y is: " << vec.y << "\n";
}
#endif // VECTORLIB_H