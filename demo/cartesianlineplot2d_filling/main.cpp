#include "wplot/CartesianPlot2D.h"
#include "wplot/Circle.h"
#include "wplot/CartesianLineGraph2D.h"
#include "wplot/CartesianGrid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Linear graph with filling demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::CartesianPlot2D* plot2D(new WPlot::CartesianPlot2D);
	WPlot::CartesianLineGraph2D::Ptr lineGraph(new WPlot::CartesianLineGraph2D);
	WPlot::CartesianGrid2D::Ptr grid(new WPlot::CartesianGrid2D);
	for (double x = 0.0; x < 8.0; x += 0.2) {
		lineGraph->appendPoint(x, sin(x));
	}
	lineGraph->setFillColor(Qt::red);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-1, 8.5, -1.0, 1.0);
	plot2D->addGraph(lineGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
