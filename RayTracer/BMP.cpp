#include "stdafx.h"
#include "BMP.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

#include "bmp.h"

using std::ofstream;
using std::sort;
using std::cout;
using std::endl;
using std::swap;
using std::ios;

// ----------------------------------------------------------------
// Local Function Prototypes
// ----------------------------------------------------------------

static void doWrite(ofstream &out, int value);
static void doWrite(ofstream &out, short value);
static void doWrite(ofstream &out, const ColorStruct &theColor);

// ----------------------------------------------------------------
// Class: Bmp
// ----------------------------------------------------------------

BMP::BMP(int width, int height) : width(width), height(height)
{
	// Initialize the entire bitmap to the default color (white)

	image = new ColorStruct*[height];
	for (int i = 0; i < height; ++i) {
		image[i] = new ColorStruct[width];
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			image[i][j] = ColorStruct();
		}
	}
}

BMP::~BMP()
{
	for (int i = 0; i < height; ++i) {
		delete[] image[i];
	}

	delete[] image;
}

// ----------------------------------------------------------------
// Draw a pixel at (x, y) with color: (red, green, blue)
// ----------------------------------------------------------------

void BMP::SetPixel(
	int x,
	int y,
	unsigned char red,
	unsigned char green,
	unsigned char blue
	)
{
	bool doSet = true;

	if (x < 0 || x >= width)
	{
		cout << "Invalid value: " << x <<
			" (expected: 0 <= x < " << width << ")" << endl;

		doSet = false;
	}

	if (y < 0 || y >= height)
	{
		cout << "Invalid value: " << y <<
			" (expected: 0 <= y < " << height << ")" << endl;

		doSet = false;
	}

	if (doSet)
		image[x][y] = ColorStruct(red, green, blue);
}

// ----------------------------------------------------------------
// Draw a pixel at (x, y) with color: theColor
// ----------------------------------------------------------------

void BMP::SetPixel(
	int x,
	int y,
	const ColorStruct &theColor
	)
{
	SetPixel(x, y, theColor.mRed, theColor.mGreen, theColor.mBlue);
}

void BMP::SetImage(Color** pixels)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			image[i][j] = ColorStruct(
				static_cast<unsigned char>(pixels[i][j].R() * 255),
				static_cast<unsigned char>(pixels[i][j].G() * 255),
				static_cast<unsigned char>(pixels[i][j].B() * 255)
				);
		}
	}
}

// ----------------------------------------------------------------
// Write our bitmap to: fileName, return true on succes,
// on error: populate errMsg, return false
// ----------------------------------------------------------------

bool BMP::SaveImageBMP(string &fileName, string &errMsg) const
{
	ofstream out(fileName.c_str(), ios::binary);

	if (out.fail())
	{
		errMsg = "Could not open: [" + fileName + "]";
		return(false);
	}

	// Header sizes ...

	const int BMP_FILE_HEADER_SIZE = 14;
	const int BMP_INFO_HEADER_SIZE = 40;

	// ----------------------------------------------
	// The bmp file header
	// ----------------------------------------------

	out.put('B');
	out.put('M');

	int fileSize =
		width * height * 3 +
		BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE;

	doWrite(out, fileSize);

	short reserved = 0;
	doWrite(out, reserved);
	doWrite(out, reserved);

	int offset = BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE;
	doWrite(out, offset);

	// ----------------------------------------------
	// The bmp information header
	// ----------------------------------------------

	int headerSize = BMP_INFO_HEADER_SIZE;
	doWrite(out, headerSize);

	doWrite(out, width);
	doWrite(out, height);

	short colorPlanes = 1;
	doWrite(out, colorPlanes);

	short bitsPerPixel = 24;
	doWrite(out, bitsPerPixel);

	int zero = 0;

	for (int i = 0; i < 6; i++)
		doWrite(out, zero);

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			doWrite(out, image[i][j]);

	out.close();

	return(true);
}

// ----------------------------------------------------------------
// Local Functions
// ----------------------------------------------------------------

static void doWrite(ofstream &out, int value)
{
	out.write((const char *)&value, sizeof(int));
}

static void doWrite(ofstream &out, short value)
{
	out.write((const char *)&value, sizeof(short));
}

static void doWrite(ofstream &out, const ColorStruct &theColor)
{
	out.write((const char *)&theColor.mBlue, sizeof(unsigned char));
	out.write((const char *)&theColor.mGreen, sizeof(unsigned char));
	out.write((const char *)&theColor.mRed, sizeof(unsigned char));
}