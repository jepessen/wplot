#include "wplot/Plot2D.h"
#include "wplot/Circle.h"
#include "wplot/BarGraph2D.h"
#include "wplot/Grid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Simple bargraph demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::BarGraph2D::Ptr barGraph(new WPlot::BarGraph2D);
	WPlot::Grid2D::Ptr grid(new WPlot::Grid2D);
	for (double x = 0.0; x < 8.0; x += 0.5) {
		barGraph->appendPoint(x, sin(x));
	}
	barGraph->setBarWidth(30);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-1, 8.5, -1.2, 1.2);
	plot2D->addGraph(barGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
