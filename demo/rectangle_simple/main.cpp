#include "wplot/Plot2D.h"
#include "wplot/Rectangle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple rectangle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Rectangle::Ptr rectangleWidget(new WPlot::Rectangle);
	WPlot::Rectangle::Ptr rectanglePlot(new WPlot::Rectangle);
	// By default widget coordinate system is used
	rectangleWidget->setDimensions(200, 150);
	rectangleWidget->setPivotPosition(WPlot::Rectangle::PIVOT_BOTTOM_CENTER);
	rectangleWidget->setPivot(150.0, 200.0);
	// Here we use the plot coordinate system
	rectanglePlot->setCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	rectanglePlot->setDimensions(2.0, 1.7);
	rectanglePlot->setPivot(0.0, 0.0);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(rectangleWidget);
	plot2D->addItem(rectanglePlot);
	plot2D->show();
	return a.exec();
}
