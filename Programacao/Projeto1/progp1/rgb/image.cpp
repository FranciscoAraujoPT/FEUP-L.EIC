#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color& fill) {
        iwidth = w;
        iheight = h;
        pixels = new color*[iwidth];
        for(int i = 0; i < iwidth; i++){
            pixels[i] = new color[iheight];
            for(int j = 0; j < iheight; j++){
                pixels[i][j] = fill;
            }
        }
    }
    image::~image() {
        for (int i = 0; i < iwidth; i++){
            delete [] pixels[i];
        }
        delete [] pixels;
    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
        for(int i = 0; i < iwidth; i++){
            for (int j = 0; j < iheight; j++) {
                pixels[i][j].invert();
            }
        }
    }
    void image::to_gray_scale() {
        for(int i = 0; i < iwidth; i++){
            for (int j = 0; j < iheight; j++) {
                pixels[i][j].to_gray_scale();
            }
        }
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
        for(int i = x; i < w+x; i++){
            for (int j = y; j < h+y; j++) {
                pixels[i][j] = c;
            }
        }
    }
    void image::replace(const color& a, const color& b) {
        for(int i = 0; i < iwidth; i++){
            for (int j = 0; j < iheight; j++) {
                if(pixels[i][j] == a){
                    pixels[i][j] = b;
                }
            }
        }
    }
    void image::add(const image& img, const color& neutral,
                    int x, int y) {
        for (int i = 0; i < img.width(); i++) {
            for (int j = 0; j < img.height(); j++) {
                if(img.pixels[i][j] != neutral){
                    pixels[x + i][y + j] = img.pixels[i][j];
                }
            }
        }
    }
    void image::crop(int x, int y, int w, int h) {
        color **auxPixels = new color*[w];
        for(int i = 0; i < w; i++){
            auxPixels[i] = new color[h];
        }
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                auxPixels[i][j] = pixels[x+i][y+j];
            }
        }

        this->~image();
        this->pixels = auxPixels;
        this->iheight = h;
        this->iwidth = w;
    }
    void image::rotate_left() {
        color **auxPixels = new color*[iheight];
        for(int i = 0; i < iheight; i++){
            auxPixels[i] = new color[iwidth];
        }

        for(int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                auxPixels[j][-i -1 + iwidth] = pixels[i][j];
            }
        }

        this->~image();
        int aux = iwidth;
        iwidth = iheight;
        iheight = aux;
        this->pixels = auxPixels;
    }
    void image::rotate_right() {
        color **auxPixels = new color*[iheight];
        for(int i = 0; i < iheight; i++){
            auxPixels[i] = new color[iwidth];
        }

        for(int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                auxPixels[-j -1 + iheight][i] = pixels[i][j];
            }
        }

        this->~image();
        int aux = iwidth;
        iwidth = iheight;
        iheight = aux;
        this->pixels = auxPixels;
    }
    void image::mix(const image& img, int factor) {
        for (int i = 0; i < img.width(); i++) {
            for (int j = 0; j < img.height(); j++) {
                    pixels[i][j].mix(img.pixels[i][j], factor);
            }
        }
    }
}
