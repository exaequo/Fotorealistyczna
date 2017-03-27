#pragma once
#include "Color.h"
#include "BMP.h"
#include <iostream>

class Image
{
public:
	Image();
	Image(const unsigned int width, const unsigned int height);
	~Image();

	void InitializePixels();
	void DestroyPixels();
	void SaveImage(std::string& filename, std::string& error);
	void SetPixel(unsigned int x, unsigned int y, const Color &color);

	unsigned int Width() const { return width; }
	void Width(unsigned int val) { width = val; }
	unsigned int Height() const { return height; }
	void Height(unsigned int val) { height = val; }
	BMP BMPImage() const { return image; }
	void BMPImage(BMP val) { image = val; }

private:
	unsigned int width;
	unsigned int height;
	Color** pixels;
	BMP image;
};

