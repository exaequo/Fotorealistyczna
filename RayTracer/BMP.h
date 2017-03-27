#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct ColorStruct
{
	ColorStruct(
		unsigned char red,
		unsigned char green,
		unsigned char blue
		) : mRed(red), mGreen(green), mBlue(blue)
	{ }

	ColorStruct() : mRed(0), mGreen(0), mBlue(0)
	{ }

	unsigned char mRed;
	unsigned char mGreen;
	unsigned char mBlue;
};

class BMP
{
public:
	BMP(int width, int height);
	~BMP();

	void SetPixel(
		int x,
		int y,
		unsigned char red,
		unsigned char green,
		unsigned char blue
		);

	void SetPixel(
		int x,
		int y,
		const ColorStruct &theColor
		);

	void SetImage(Color** pixels);

	bool SaveImageBMP(string &fileName, string &errMsg) const;

private:

	int width;
	int height;
	ColorStruct **image;
};

