#pragma once
#include "Color.h"
#include "BMP.h"

class Image
{
public:
	Image();
	Image(const unsigned int width, const unsigned int height);
	~Image();

	void CalculatePixelDimensions();
	void InitializePixels();
	void DestroyPixels();
	void SaveImage(std::string& filename, std::string& error);
	void SetPixel(unsigned int x, unsigned int y, const Color &color);

	unsigned int Width() const { return width; }
	void Width(unsigned int val) { width = val; }
	unsigned int Height() const { return height; }
	void Height(unsigned int val) { height = val; }
	float PixelWidth() const { return pixelWidth; }
	void PixelWidth(float val) { pixelWidth = val; }
	float HalfPixelWidth() const { return halfPixelWidth; }
	void HalfPixelWidth(float val) { halfPixelWidth = val; }
	float PixelHeight() const { return pixelHeight; }
	void PixelHeight(float val) { pixelHeight = val; }
	float HalfpixelHeight() const { return halfpixelHeight; }
	void HalfpixelHeight(float val) { halfpixelHeight = val; }
	BMP BMPImage() const { return image; }
	void BMPImage(BMP val) { image = val; }
private:
	unsigned int width;
	unsigned int height;
	float pixelWidth;
	float halfPixelWidth;
	float pixelHeight;
	float halfpixelHeight;
	Color** pixels;
	BMP image;
};

