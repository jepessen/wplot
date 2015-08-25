#include "wplot/Plot2D.h"
#include "wplot/Arrow2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Styled arrow inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Arrow2D::Ptr arrow(new WPlot::Arrow2D);
	arrow->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_BOTH);
	arrow->setDimensionCoordinates(WPlot::Item2D::COORDINATE_WIDGET, WPlot::Item2D::AXIS_BOTH);
	arrow->setPivot(0.0, 0.0);
	arrow->setFinalPoint(2.5, 3.7);
	arrow->setArrowWidth(20.0);
	arrow->setArrowLength(15.0);
	arrow->setLineColor(Qt::green);
	arrow->setArrowLineColor(Qt::red);
	arrow->setArrowFillColor(Qt::yellow);
	arrow->setLineStyle(Qt::DashDotLine);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(arrow);
	plot2D->show();
	return a.exec();
}
