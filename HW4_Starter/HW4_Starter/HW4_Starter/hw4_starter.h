#ifndef HW4_STARTER_H
#define HW4_STARTER_H

#include <QtWidgets/QMainWindow>
#include "ui_hw4_starter.h"
#include "Steganography.h"

class HW4_Starter : public QMainWindow
{
	Q_OBJECT

public:
	HW4_Starter(QWidget *parent = 0);
	~HW4_Starter();

private:
	Ui::HW4_StarterClass ui;
	//object for steganography here
	Steganography steganography;
	QString messageFile;
	const char* secretMessage;
	QImage *imageObject;

public slots:
	void loadFile(void);
	void saveFile(void);
	void handleReadButton(void);
	void handleWriteButton(void);

signals:
	void sendPixmap(QPixmap);
};

#endif // HW4_STARTER_H
