#pragma once

#include "Colors.h"
#include <string>
#include "RectI.h"

class Surface
{

public: 
	Surface(const std::string& filename);
	Surface(int width, int height); // input constructor
	Surface(const Surface& rhs); // copy constructor
	~Surface(); // Destructor
	Surface& operator=( const Surface& rhs); // Copy assignment operator
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI getRect() const;

private:
	Color* pPixels = nullptr; //pointer to the pixels
	int width; 
	int height;
	bool reverse = false;
	

};