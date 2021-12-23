
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    //! \brief Script class used Script manipulations
    class script {
    private:
        //! \brief Fills a rectangle with a color in the image
        //! \see image#fill(int x, int y, int w, int h, const color& c)
        void fill();

        //! \brief Initialize a new Image through a filename (png only)
        void open();

        //! \brief Initialize a new Image with a new dimension and color.
        void blank();

        //! \brief Saves the image to a png.
        void save();

        //! \brief Replace the Original color with the second color.
        //! \see image#replace(const color& a, const color& b)
        void replace();

        //! \brief Crop the image to a new size.
        //! \see image#crop(int x, int y, int w, int h)
        void crop();

        //! \brief Adds the content of a Image to the original Image.
        //! \see image#add(const image& img, const color& neutral, int x, int y)
        void add();

        //! \brief Mix the Image with another Image with a factor (0-100).
        //! \see image#mix(const image& img, int factor)
        void mix();
    public:
        //! Creates a new Script object with filename provided where new commands can be order to manipulate the Image Object.
        //! \brief Creates a new Script object with filename provided
        //! \param filename The image
        script(const std::string& filename);

        //! \brief Default destructor.
        ~script();

        //! \brief Function that accepts arguments in order to manipulate the Image Object.
        void process();
    private:
        //! \brief Image Object that is to be manipulated by the Script content.
        image* img;
        //! \brief Input stream class to operate on files
        std::ifstream input;
        //! \brief String where the absolute path for where the project is located is store.
        std::string root_path;
    };
}
#endif
