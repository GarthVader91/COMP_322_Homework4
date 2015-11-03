#include "BMP_Handler.h"

#pragma once
class Steganography
{
public:
	Steganography(void);
	~Steganography(void);

	char* readMessage(const char* filename);
	void writeMessage(const char* filename, const char* newMessage);
	int width;
	int height;
	unsigned char* pixelArray;
	const char* messageToSend;
	int stringLength;
private:
	BMP_Handler *bmp;
};

