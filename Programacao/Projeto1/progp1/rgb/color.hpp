//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;
    //! @brief Color class used for color manipulations.
    class color {
    private:
        //! \brief Value that represent the amount of red in the color.
        rgb_value r;

        //! \brief Value that represent the amount of green in the color.
        rgb_value g;

        //! \brief Value that represent the amount of blue in the color.
        rgb_value b;
    public:
        //! \brief Constant for the color Red, rgb(255, 0, 0).
        static const color RED;

        //! \brief Constant for the color Green, rgb(0, 255, 0).
        static const color GREEN;

        //! \brief Constant for the color Blue, rgb(0, 0, 255).
        static const color BLUE;

        //! \brief Constant for the color Black, rgb(0, 0, 0).
        static const color BLACK;

        //! \brief Constant for the color White, rgb(255, 255, 255).
        static const color WHITE;

        //! Creates a new Color object with the rgb(0, 0, 0).
        //! \brief Default constructor.
        //! \see color(const color &c)
        //! \see color(rgb_value r, rgb_value g, rgb_value b)
        color();

        //! Creates a new Color object from another Color object.
        //! \brief Copy constructor.
        //! \param color Another Color object to copy from.
        //! \see color()
        //! \see color(rgb_value r, rgb_value g, rgb_value b)
        color(const color &c);

        //! Creates a new Color object from the given rgb values.
        //! \brief Constructor.
        //! \param r A value from 0 to 255 representing the amount of red in the color.
        //! \param g A value from 0 to 255 representing the amount of green in the color.
        //! \param b A value from 0 to 255 representing the amount of blue in the color.
        //! \see color()
        //! \see color(rgb_value r, rgb_value g, rgb_value b)
        color(rgb_value r, rgb_value g, rgb_value b);

        //! \brief A getter for the the variable /ref r.
        //! \return A value that goes from 0 to 255 representing the amount of red in the color.
        rgb_value red() const;

        //! \brief A setter for the variable /ref r.
        //! \return A value that goes from 0 to 255 representing the amount of red in the color that can be changed.
        rgb_value& red();

        //! \brief A getter for the the variable /ref g.
        //! \return A value that goes from 0 to 255 representing the amount of green in the color.
        rgb_value green() const;

        //! \brief A setter for the variable /ref g.
        //! \return A value that goes from 0 to 255 representing the amount of green in the color that can be changed.
        rgb_value& green();

        //! \brief A getter for the the variable /ref b.
        //! \return A value that goes from 0 to 255 representing the amount of blue in the color.
        rgb_value blue() const;

        //! \brief A setter for the variable /ref b.
        //! \return A value that goes from 0 to 255 representing the amount of blue in the color that can be changed.
        rgb_value& blue();

        //! \brief Assignment overloading.
        //! \param color Another Color object.
        //! \return The reference to the current Color object.
        color& operator=(const color&c);

        //! \brief Equivalence overloading.
        //! \param color Another Color object.
        //! \return Return a boolean that is true when the rgb from both color are the same, and that is false otherwise.
        bool operator==(const color &c) const;

        //! \brief Inequality overloading.
        //! \param color Another Color object.
        //! \return Return a boolean that is false when the rgb from both color are the same, and that is true otherwise.
        bool operator!=(const color &c) const;

        //! Inverts the color of the Color Object, i.e. the rgb of the Color Object will became its opposite.
        //! \brief Inverts the color.
        void invert();

        //! Turns the color of the Color Object to a color from the range of gray shades from white to black.
        //! \brief Turn the color in a shades of gray.
        void to_gray_scale();

        //! Mix the color from the Color Object with another color with a factor where the final color rgb is (r,g,b)↦(m(r,c.r),m(g,c.g),m(b,c.b)) and m(a,b)=((100−f)a+fb)/100.
        //! \brief Mix the color with another color with a factor from 0 to 100.
        //! \param c Another Color object.
        //! \param f Factor that determine the amount of the given color is used to mix, this value must be from 0 to 100.
        void mix(const color& c, int f);
    };
}
#endif
