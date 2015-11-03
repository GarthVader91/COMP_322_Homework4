#include "Steganography.h"


//These just used for testing
#include <fstream>
#include <iostream>
using namespace std;

Steganography::Steganography(void)
{
	width = 0;
	height = 0;
}


Steganography::~Steganography(void)
{
}

char* Steganography::readMessage(const char* filename)
{
	int imageBit = 0;
	int imageByte = 0;
	char* temp = new char[width*height*4];

	ofstream myfile;
	myfile.open("temp.txt");

	pixelArray = bmp->loadBMP(filename, width, height);

	int p = 0;
	int j = 0;
	//Continues until end of message is reached
	while(temp[p] != '\0')
	{
		for (j; j <= 7; j++)
		{
			imageBit = (pixelArray[imageByte] & 1);
			myfile << imageBit << "\n";
			if(imageBit)
				temp[p] |= (1U << (j));
			else
				temp[p] &= ~(1U << (j));

			//moves to next byte
			imageByte += 1;
		}

		//Resets 'j' value
		j = 0;
		p++;
	}

	//Saves image
	bmp->saveBMP(filename, pixelArray, width, height);
	myfile.close();

	return temp;
}

void Steganography::writeMessage(const char* filename, const char* newMessage)
{
	pixelArray = bmp->loadBMP(filename, width, height);

	ofstream myfile;
	myfile.open ("writeTest.txt");
	myfile << newMessage << "\n";

	int messageBit = 0;
	int imageBit = 0;

	int p = 0;
	int j = 0;
	int imageByte = 0;

	//Continues until end of message is reached
	while(newMessage[p] != '\0')
	{
		for (j; j <= 7; j++)
		{
			messageBit = ((newMessage[p] >> j) & 1);
			if(messageBit)
			{
				//imageBit = test[imageByte] & 1;//Checks bit
				pixelArray[imageByte] &= 0xFE;
				pixelArray[imageByte] |= (1U << (1 - 1));//Set least significant bit of first byte of image to 1
			}
			else
			{
				pixelArray[imageByte] &= 0xFE;
				pixelArray[imageByte] &= ~(1U << (1 - 1));//Otherwise set it to 0
			}

			//moves to next byte
			imageByte += 1;
		}

		//Resets 'j' value
		j = 0;
		myfile << newMessage[p] << "\n";
		p++;
	}

	//Stuffs null character
	for(int k = 0; k < 8; k++)
	{
		pixelArray[imageByte] &= 0xFE;//zeros out buffer
		pixelArray[imageByte] |= (char)(('\0' >> k) & 1);
		imageByte += 1;
	}

	//Fills int the rest of the bmp file


	myfile.close();

	//Saves image
	bmp->saveBMP(filename, pixelArray, width, height);
}