#include "wplot/Plot2D.h"
#include "wplot/Rectangle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Styled rectangle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Rectangle::Ptr rectangle(new WPlot::Rectangle);
	rectangle->setCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	rectangle->setDimensions(2.0, 1.7);
	rectangle->setPivot(0.0, 0.0);
	rectangle->setLineColor(Qt::red);
	rectangle->setLineWidth(2.5);
	rectangle->setLineStyle(Qt::DashDotLine);
	rectangle->setFillColor(Qt::blue);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(rectangle);
	plot2D->show();
	return a.exec();
}
