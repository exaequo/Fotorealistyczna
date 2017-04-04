#include "stdafx.h"
#include "Image.h"

Image::Image() :
	width(800),
	height(600),
	image(BMP(width, height))
{
	InitializePixels();
	CalculatePixelDimensions();
}

Image::Image(const unsigned int width, const unsigned int height) :
	width(width),
	height(height),
	image(BMP(width, height))
{
	InitializePixels();
	CalculatePixelDimensions();
}

Image::~Image()
{
	DestroyPixels();
}

void Image::CalculatePixelDimensions()
{
	pixelWidth = 1.0f / width;
	pixelHeight = 1.0f / height;
	halfPixelWidth = 0.5f * pixelWidth;
	halfpixelHeight = 0.5f * pixelHeight;
}

void Image::InitializePixels()
{
	pixels = new Color*[height];
	for (size_t i = 0; i < height; ++i) {
		pixels[i] = new Color[width];
	}

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			pixels[i][j] = Color();
		}
	}
}

void Image::DestroyPixels()
{
	for (size_t i = 0; i < height; ++i) {
		delete[] pixels[i];
	}
	delete[] pixels;
}

void Image::SaveImage(std::string& filename, std::string& error)
{
	image.SetImage(pixels);
	image.SaveImageBMP(filename, error);
}

void Image::SetPixel(unsigned int x, unsigned int y, const Color &color)
{
	pixels[x][y] = color;
}

