#include "Surface.h"
#include "ChiliWin.h"
#include <cassert>
#include <fstream>

Surface::Surface(const std::string & filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file); // converts file to a bool to output if there is a problem with the file
	BITMAPFILEHEADER bmFileHeader;
	file.read(reinterpret_cast<char*>(&bmFileHeader), sizeof(bmFileHeader));

	BITMAPINFOHEADER bmInfoHeader;
	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));
	assert(bmInfoHeader.biBitCount == 24 || bmInfoHeader.biBitCount == 32);
	assert(bmInfoHeader.biCompression == BI_RGB);

	width = bmInfoHeader.biWidth;
	height = bmInfoHeader.biHeight;

	
	if (bmInfoHeader.biHeight < 0)
	{
		height = -bmInfoHeader.biHeight;
		reverse = true; 
	}

	pPixels = new Color[width* height];

	file.seekg(bmFileHeader.bfOffBits);
	const int padding = (4 - (width * 3) % 4) % 4; //pixel is 3 bytes, but there is padding between rows.
	// taking the modulus twice is a method of including all possible remaining values, including 0 padding. 
	if (reverse == true)
	{
		if (bmInfoHeader.biBitCount == 24)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					PutPixel(x, y, Color(file.get(), file.get(), file.get()));
				}
				file.seekg(padding, file.cur); //file.cur means current position in file!
			}
		}
		if (bmInfoHeader.biBitCount == 32)
		{
			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					PutPixel(x, y, Color(file.get(), file.get(), file.get(), file.get()));
				}
				file.seekg(padding, file.cur); //file.cur means current position in file!
			}
		}
	}
	else
	{
		if (bmInfoHeader.biBitCount == 24)
		{
			for (int y = height - 1; y >= 0; y--)
			{
				for (int x = 0; x < width; x++)
				{
					PutPixel(x, y, Color(file.get(), file.get(), file.get()));
				}
				file.seekg(padding, file.cur); //file.cur means current position in file!
			}
		}
		if (bmInfoHeader.biBitCount == 32)
		{
			for (int y = height - 1; y >= 0; y--)
			{
				for (int x = 0; x < width; x++)
				{
					PutPixel(x, y, Color(file.get(), file.get(), file.get(), file.get()));
				}
				file.seekg(padding, file.cur); //file.cur means current position in file!
			}
		}
	}
}

Surface::Surface(int width, int height)
	:
	width(width),
	height(height),
	pPixels( new Color[width*height] )
{
}

Surface::Surface(const Surface & rhs)
	:
	Surface(rhs.width, rhs.height)
{
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
}

Surface::~Surface()
{
	delete [] pPixels;
	pPixels = nullptr;
}

Surface & Surface::operator=(const Surface & rhs)
{
	width = rhs.width;
	height = rhs.height;

	delete [] pPixels;
	pPixels = new Color[width*height];
	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}
	return *this;
}

void Surface::PutPixel(int x, int y, Color c)
{
	pPixels[y*width + x] = c;
}

Color Surface::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

int Surface::GetWidth() const
{
	return width;
}

int Surface::GetHeight() const
{
	return height;
}

RectI Surface::getRect() const
{
	return { 0, width, 0, height };
}


