#include "wplot/Plot2D.h"
#include "wplot/Background.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Background gradient color demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Background::Ptr background(new WPlot::Background);
	QLinearGradient gradient(QPointF(0, 0), QPointF(1, 1));
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::blue);
	gradient.setCoordinateMode(QGradient::StretchToDeviceMode);
	background->setGradient(gradient);
	plot2D->setBackground(background);
	plot2D->show();
	return a.exec();
}
