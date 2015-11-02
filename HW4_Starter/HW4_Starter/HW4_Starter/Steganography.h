#include "BMP_Handler.h"

#pragma once
class Steganography
{
public:
	Steganography(void);
	~Steganography(void);

	void readMessage(const char* filename);
	int width;
	int height;
private:
	BMP_Handler *bmp;
};

