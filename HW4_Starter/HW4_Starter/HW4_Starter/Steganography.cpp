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

void Steganography::readMessage(const char* filename)
{
	const unsigned char* test;
	test = bmp->loadBMP(filename, width, height);
	bmp->saveBMP(filename, test, width, height);

	ofstream myfile;
	myfile.open ("example.txt");
	myfile << "The width is " << width << "\n";
	myfile << "The height is " << height << "\n";
	myfile.close();

}