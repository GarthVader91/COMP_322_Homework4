#include "hw4_starter.h"

#include <QString>
#include <QFileDialog>
#include <iostream>
#include "Windows.h"

using namespace std;

HW4_Starter::HW4_Starter(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
}

HW4_Starter::~HW4_Starter()
{

}

void HW4_Starter::loadFile() {
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Images (*.bmp)"));

	if(filename != QString()) {
		emit sendPixmap(QPixmap(filename));
	}
}
void HW4_Starter::handleReadButton()
{	
	messageFile = filename.toStdString().c_str();
	//steganography.readMessage("test.bmp");
	if(messageFile != NULL)
		steganography.readMessage(messageFile);
}