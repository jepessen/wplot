#include "wplot/Plot2D.h"
#include "wplot/Background.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Background solid color demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Background::Ptr background(new WPlot::Background);
	background->setColor(Qt::yellow);
	plot2D->setBackground(background);
	plot2D->show();
	return a.exec();
}
