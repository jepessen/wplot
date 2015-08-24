#include "wplot/Plot2D.h"
#include "wplot/Circle.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Circle::Ptr circleWidget(new WPlot::Circle);
	WPlot::Circle::Ptr circlePlot(new WPlot::Circle);
	// By default widget coordinate system is used
	circleWidget->setRadius(25);
	circleWidget->setPivot(100.0, 50.0);
	// Here we use the plot coordinate system
	circlePlot->setCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	circlePlot->setRadius(1.3);
	circlePlot->setPivot(0.0, 0.0);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(circleWidget);
	plot2D->addItem(circlePlot);
	plot2D->show();
	return a.exec();
}
