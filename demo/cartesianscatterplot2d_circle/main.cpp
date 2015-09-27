#include "wplot/CartesianPlot2D.h"
#include "wplot/Circle.h"
#include "wplot/CartesianScatterGraph2D.h"
#include "wplot/CartesianGrid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Simple circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::CartesianPlot2D* plot2D(new WPlot::CartesianPlot2D);
	WPlot::Circle::Ptr circlePlot(new WPlot::Circle);
	WPlot::CartesianScatterGraph2D::Ptr scatterGraph(new WPlot::CartesianScatterGraph2D);
	WPlot::CartesianGrid2D::Ptr grid(new WPlot::CartesianGrid2D);
	// Here we use the plot coordinate system
	circlePlot->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	circlePlot->setDimensionCoordinates(WPlot::Item2D::COORDINATE_WIDGET, WPlot::Item2D::AXIS_X);
	circlePlot->setRadius(10);
	scatterGraph->setItem(circlePlot);
	for (double x = 0.0; x < 8.0; x += 0.2) {
		scatterGraph->appendPoint(x, sin(x));
	}
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-1, 8.5, -1.0, 1.0);
	plot2D->addGraph(scatterGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
