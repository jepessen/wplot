#include "wplot/CartesianPlot2D.h"
#include "wplot/CartesianGrid2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Grid with color applied demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::CartesianPlot2D* plot2D(new WPlot::CartesianPlot2D);
	WPlot::CartesianGrid2D::Ptr grid(new WPlot::CartesianGrid2D);
	grid->setPrimaryXColor(Qt::yellow);
	grid->setSecondaryXColor(Qt::red);
	grid->setPrimaryYColor(Qt::green);
	grid->setSecondaryYColor(Qt::blue);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
