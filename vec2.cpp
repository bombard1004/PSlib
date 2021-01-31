// vec2.cpp
// author bombard1004
// last_update Jan 31 2021

#include <bits/stdc++.h>

class Vec2 {
private:
    double x, y;

public:
    Vec2(double _x, double _y) {
        x = _x;
        y = _y;
    }

    Vec2 operator + (const Vec2 &rhs) {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator - (const Vec2 &rhs) {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    double cross(const Vec2 &rhs) {
        return x * rhs.y - rhs.x * y;
    }
};
