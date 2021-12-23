//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    //! @brief Image class used for image manipulations.
    class image {
    private:
        //! \brief Value that represent the width of the image.
        int iwidth;
        //! \brief Value that represent the height of the image.
        int iheight;
        //! \brief A two dimensional array that contain every pixel(represented by a color) of the image.
        color **pixels;
    public:
        //! Creates a new Image object with width and height provided and fill it with the color given. If no color is given the the color White is use.
        //! \brief Default constructor.
        image(int w, int h, const color& fill = color::WHITE);

        //! \brief Default destructor.
        ~image();

        //! \brief Function to get the image width.
        //! \return The width of the image in pixels, i.e., return the number of rows the variable \ref pixels has.
        int width() const;
        //! \brief Function to get the image height.
        //! \return The height of the image in pixels, i.e., return the number of columns the variable \ref pixels has.
        int height() const;

        //! \brief Function to know the Color object at a certain position in the Image.
        //! \param x Position in the x-axis.
        //! \param y Position in the y-axis.
        //! \return The color at the position (x,y) in /ref pixels.
        color& at(int x, int y);

        //! \brief Function to get the Color object at a certain position in the Image.
        //! \param x Position in the x-axis.
        //! \param y Position in the y-axis.
        //! \return The non-mutable color at the position (x,y) in /ref pixels.
        const color& at(int x, int y) const;

        //! Inverts the color of every pixel in image, i.e. the rgb of the all the pixels will became its opposite.
        //! \brief Inverts the image.
        //! \see color#invert()
        void invert();

        //! Turns the color of each pixel of the image to a color from the range of gray shades from white to black.
        //! \brief Turn the colors of the image in a shades of gray.
        //! \see color#to_gray_scale()
        void to_gray_scale();

        //! Search the whole image for the pixels with color a and replace them with the color b.
        //! \brief Replace the Original color with the second color.
        //! \param a Original color that is to be replace.
        //! \param b Color that will replace the original color.
        void replace(const color& a, const color& b);

        //! Defines a color c for every pixel that is in the rectangle define by the four initial parameters.
        //! \brief Fills a rectangle with a color in the image.
        //! \param x Initial position in the x-axis where the rectangle will be define.
        //! \param y Initial position in the y-axis where the rectangle will be define.
        //! \param w Final position in the x-axis where the rectangle will be define.
        //! \param h Final position in the y-axis where the rectangle will be define.
        //! \param c Color that will replace the originals pixels inside the rectangle.
        void fill(int x, int y, int w, int h, const color& c);

        //! Mix the Image with another Image with a factor, that can go from 0 to 100, where, for every position, the pixel is mix with the correspondent pixel from the given Image (using the color::mix() function).
        //! \brief Mix the Image with another Image with a factor (0-100).
        //! \param img Image that will be mix with the original Image.
        //! \param factor A number from 0 to 100 that define the amount, of the given Image, that will be mix.
        //! \see color#mix(const color& c, int f)
        void mix(const image& img, int factor);

        //! From the parameters a rectangle will be define inside the Image forming a new image. That image will be save while the rest is deleted.
        //! \brief Crop the image to a new size define by the parameters.
        //! \param x Initial position in the x-axis where the rectangle will be define.
        //! \param y Initial position in the y-axis where the rectangle will be define.
        //! \param w Final position in the x-axis where the rectangle will be define.
        //! \param h Final position in the y-axis where the rectangle will be define.
        void crop(int x, int y, int w, int h);

        //! Rotate the Image by 90º anti-clockwise pivoting by the center.
        //! \brief Rotate the Image by 90º anti-clockwise.
        void rotate_left();

        //! Rotate the Image by 90º clockwise pivoting by the center.
        //! \brief Rotate the Image by 90º clockwise.
        void rotate_right();

        //! Adds the content of the given Image replacing the old one for evey pixel starting in the position (x,y), given by the last two parameters, but not the ones with the color neutral (given by the second parameter).
        //! \brief Adds the content of a Image to the original Image.
        //! \param img Image that will replace the original Image
        //! \param neutral Color that if a pixel of the img contain should not replace the original pixel.
        //! \param x Initial position in the x-axis where the given Image will be draw.
        //! \param y Initial position in the y-axis where the given Image will be draw
        void add(const image& img, const color& neutral,
                 int x, int y);
    };
}


#endif
