#include "wplot/Plot2D.h"
#include "wplot/Circle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Styled circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Circle::Ptr circle(new WPlot::Circle);
	circle->setCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	circle->setRadius(1.3);
	circle->setPivot(0.0, 0.0);
	circle->setLineColor(Qt::red);
	circle->setLineStyle(Qt::DashDotLine);
	circle->setLineWidth(3.0);
	circle->setFillColor(Qt::green);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(circle);
	plot2D->show();
	return a.exec();
}
