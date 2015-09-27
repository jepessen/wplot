#include "wplot/PolarPlot2D.h"
#include "wplot/Circle.h"
#include "wplot/PolarLineGraph2D.h"
#include "wplot/PolarGrid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Simple circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::PolarPlot2D* plot2D(new WPlot::PolarPlot2D);
	WPlot::PolarLineGraph2D::Ptr lineGraph(new WPlot::PolarLineGraph2D);
	WPlot::PolarGrid2D::Ptr grid(new WPlot::PolarGrid2D);
	for (double x = 0.0; x < 3.14; x += 0.01) {
		lineGraph->appendPoint(x, sin(x));
	}
	lineGraph->setLineColor(Qt::red);
	lineGraph->setLineStyle(Qt::DashLine);
	lineGraph->setFillColor(Qt::green);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->addGraph(lineGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
