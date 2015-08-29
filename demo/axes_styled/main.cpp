#include "wplot/Plot2D.h"
#include "wplot/Axes2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple axes inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Axes2D::Ptr axes(new WPlot::Axes2D);
	axes->setOrigin(0.5, 1.3);
	axes->setAxisXColor(Qt::red);
	axes->setAxisYColor(Qt::blue);
	axes->setAxisXStyle(Qt::DashDotLine);
	axes->setAxisXArrowDimensions(30, 40);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addAxes(axes);
	plot2D->show();
	return a.exec();
}
