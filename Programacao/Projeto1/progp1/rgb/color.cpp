#include <rgb/color.hpp>

namespace rgb {
    const color color::BLACK(0,0,0);
    const color color::WHITE(255,255,255);
    const color color::RED(255,0,0);
    const color color::GREEN(0,255,0);
    const color color::BLUE(0,0,255);
    color::color() {
        r = 0;
        g = 0;
        b = 0;
    }
    color::color(const color& other) {
        r = other.r;
        g = other.g;
        b = other.b;
    }
    color::color(rgb_value red, rgb_value green, rgb_value blue) {
        r = red;
        g = green;
        b = blue;
    }
    rgb_value color::red() const {
        return r;
    }
    rgb_value color::green() const {
        return g;
    }
    rgb_value color::blue() const {
        return b;
    }
    rgb_value& color::red()  {
        return r;
    }
    rgb_value& color::green()  {
        return g;
    }
    rgb_value& color::blue()  {
        return b;
    }
    color& color::operator=(const color& c) {
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }
    bool color::operator==(const color &c) const {
        return r == c.r && g == c.g && b == c.b;
    }
    bool color::operator!=(const color &c) const {
        return r != c.r || g != c.g || b != c.b;
    }
    void color::invert() {
        r = WHITE.r - r;
        g = WHITE.g - g;
        b = WHITE.b - b;
    }
    void color::mix(const color& c, int f) {
        *this = color(((100-f)*r+f*c.r)/100, ((100-f)*g+f*c.g)/100, ((100-f)*b+f*c.b)/100);
    }
    void color::to_gray_scale() {
        const int v = (r + g + b)/3;
        *this = color(v,v,v);
    }
}