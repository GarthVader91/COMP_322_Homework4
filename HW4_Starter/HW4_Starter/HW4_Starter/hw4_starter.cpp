#include "hw4_starter.h"

#include <QString>
#include <QFileDialog>
#include <iostream>
#include "Windows.h"
#include <fstream>

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

	filename = filename.section('/',-1);

	messageFile = filename;
}
void HW4_Starter::handleReadButton()
{	
	if(messageFile != NULL)
		steganography.readMessage(messageFile.toStdString().c_str());
}

void HW4_Starter::handleWriteButton()
{
	QString message = ui.messageEdit->toPlainText();

	ofstream myfile;
	myfile.open ("secret.txt");
	myfile << message.toStdString() << "\n";
	myfile.close();
}