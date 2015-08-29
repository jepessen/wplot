#include "wplot/Plot2D.h"
#include "wplot/Arrow2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple arrow inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Arrow2D::Ptr arrowWidget(new WPlot::Arrow2D);
	WPlot::Arrow2D::Ptr arrowPlot(new WPlot::Arrow2D);
	// By default widget coordinate system is used
	arrowWidget->setPivot(150.0, 200.0);
	arrowWidget->setFinalPoint(400.0, 343.0);
	arrowWidget->setArrowWidth(30.0);
	arrowWidget->setArrowLength(20.0);
	// Here we use the plot coordinate system
	arrowPlot->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_BOTH);
	arrowPlot->setDimensionCoordinates(WPlot::Item2D::COORDINATE_WIDGET, WPlot::Item2D::AXIS_BOTH);
	arrowPlot->setPivot(0.0, 0.0);
	arrowPlot->setFinalPoint(0.5, 0.7);
	arrowPlot->setArrowWidth(20.0);
	arrowPlot->setArrowLength(15.0);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(arrowWidget);
	plot2D->addItem(arrowPlot);
	plot2D->show();
	return a.exec();
}
