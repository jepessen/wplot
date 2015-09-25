#include "wplot/CartesianPlot2D.h"
#include "wplot/CartesianGrid2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Basic grid demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::CartesianPlot2D* plot2D(new WPlot::CartesianPlot2D);
	WPlot::CartesianGrid2D::Ptr grid(new WPlot::CartesianGrid2D);
	plot2D->setPadding(15, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3.1, 7.2, -2, 4.3);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
