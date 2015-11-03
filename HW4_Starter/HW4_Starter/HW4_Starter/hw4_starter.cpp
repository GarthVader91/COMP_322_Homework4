#include "hw4_starter.h"

#include <QString>
#include <QFileDialog>
#include <iostream>
#include "Windows.h"
#include <fstream>
#include <string>

using namespace std;

HW4_Starter::HW4_Starter(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	imageObject = new QImage();
}

HW4_Starter::~HW4_Starter()
{

}

void HW4_Starter::saveFile()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), QString(), tr("Images (*.bmp)"));

	if(filename != QString()) {
		imageObject->save(filename);
	}
}

void HW4_Starter::loadFile() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Images (*.bmp)"));

	if(filename != QString()) {
		emit sendPixmap(QPixmap(filename));
		imageObject->load(filename);
	}

	filename = filename.section('/',-1);

	messageFile = filename;
}


void HW4_Starter::handleReadButton()
{	
	char* temp;

	if(messageFile != NULL)
		temp = steganography.readMessage(messageFile.toStdString().c_str());

	ui.messageEdit->setText(temp);
}

void HW4_Starter::handleWriteButton()
{
#pragma region getText
	QString message = ui.messageEdit->toPlainText();
	string temp = "";
	temp = message.toStdString();

	//Converts string to const char*
	secretMessage = temp.c_str();

	ofstream myfile;
	myfile.open ("secret.txt");
	myfile << secretMessage << "\n";
#pragma endregion

	steganography.writeMessage("test.bmp", secretMessage);

	myfile << "\n";	
	myfile.close();
}