#include "wplot/Plot2D.h"
#include "wplot/Circle.h"
#include "wplot/LineGraph2D.h"
#include "wplot/Grid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Simple circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::LineGraph2D::Ptr lineGraph(new WPlot::LineGraph2D);
	WPlot::Grid2D::Ptr grid(new WPlot::Grid2D);
	for (double x = 0.0; x < 8.0; x += 0.2) {
		lineGraph->appendPoint(x, sin(x));
	}
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-1, 8.5, -1.0, 1.0);
	plot2D->addGraph(lineGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
