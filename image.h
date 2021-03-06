//Image.h
//
//Class representing an image
//  original by Wagner Correa, 1999
//  turned to C++ by Robert Osada, 2000
//  updated by Stephen J. Guy, 2017

#ifndef IMAGE_INCLUDED
#define IMAGE_INCLUDED
#include <vector>
#include <assert.h>
#include <stdio.h>
#include "pixel.h"
#include "camera.h"
#include "Vec3.h"
#include "sphere.h"
#include "scene.h"

using std::vector;




#include "stb_image.h"
#include "stb_image_write.h"

/**
 * constants
 **/
enum {
    IMAGE_SAMPLING_POINT,
    IMAGE_SAMPLING_BILINEAR,
    IMAGE_SAMPLING_GAUSSIAN,
    IMAGE_N_SAMPLING_METHODS
};

enum {
    IMAGE_CHANNEL_RED,
    IMAGE_CHANNEL_GREEN,
    IMAGE_CHANNEL_BLUE,
    IMAGE_CHANNEL_ALPHA,
    IMAGE_N_CHANNELS
};


/**
 * Image
 **/
class Image
{
public:
    //A union lets us view the data two differen ways
    // either as a collection of pixels (for easy per-pixel processing), and
    // or as just a list of raw bytes (for loading from a file, or cute tricks like quickly setting everything to 0)
    union PixelData{
       Pixel *pixels;
       uint8_t *raw;
    };

    PixelData data;
    //PixelInfo *pixels; //pixel array
    //uint8_t *pixelData;
    int width, height, num_pixels;
    int sampling_method;
	//BMP* bmpImg;

public:
    // Creates a blank image with the given dimensions
    Image (int width, int height);

    // Copy iamage
    Image (const Image& src);

	// Make image from file
	Image(char *fname);

    // Destructor
    ~Image ();

    // Pixel access
    int ValidCoord (int x, int y)  const { return x>=0 && x<width && y>=0 && y<height; }
    Pixel& GetPixel (int x, int y) const { assert(ValidCoord(x,y));  return data.pixels[y*width + x]; }
    void SetPixel (int x, int y, Pixel p) const { assert(ValidCoord(x,y));  data.pixels[y*width + x] = p; }

    // Dimension access
    int Width     () const { return width; }
    int Height    () const { return height; }
    int NumPixels () const { return num_pixels; }

	// Make file from image
	void Write( const char *fname );

    // Adds noise to an image.  The amount of noise is given by the factor
    // in the range [0.0..1.0].  0.0 adds no noise.  1.0 adds a lot of noise.

    // Scales an image in x by sx, and y by sy.
    Image* Scale(double sx, double sy);

    // Rotates an image by the given angle.
    Image* Rotate(double angle);

    // Warps an image using a creative filter of your choice.
    void Fun();

    // Sets the sampling method.
    void SetSamplingMethod(int method);;
    // Sample image using current sampling method.
    Pixel Sample(double u, double v);
    void changebackground(float r, float g, float b);
    void ConstructrayThroughPixel(Camera camera,Scene s,vector<Light*> lights);
  //  bool raySphereIntersect(Vec3 eye,Vec3 raydir,Vec3 sperePos,float sphereRadius);

};

#endif
