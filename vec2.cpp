// vec2.cpp
// author bombard1004
// last_update Mar 27 2021

#include <bits/stdc++.h>

class Vec2 {
private:
    double _x, _y;

public:
    Vec2(const double &x_in, const double &y_in): _x(x_in), _y(y_in) {}

    double x() const {return _x;}
    double y() const {return _y;}

    Vec2 operator + (const Vec2 &rhs) const {
        return Vec2(_x + rhs._x, _y + rhs._y);
    }

    Vec2 operator - (const Vec2 &rhs) const {
        return Vec2(_x - rhs._x, _y - rhs._y);
    }

    Vec2 operator / (const double &d) const {
        return Vec2(_x/d, _y/d);
    }

    double cross(const Vec2 &rhs) const {
        return _x * rhs._y - rhs._x * _y;
    }

    void rotate(double angle, bool rad = true) {
        if(!rad)
            angle = acos(-1) / 180 * angle;
        double rotated_x = _x * cos(angle) - _y * sin(angle);
        double rotated_y = _x * sin(angle) + _y * cos(angle);
        _x = rotated_x; _y = rotated_y;
    }
};
