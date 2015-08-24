#include "wplot/Plot2D.h"
#include "wplot/Grid2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Grid with color applied demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Grid2D::Ptr grid(new WPlot::Grid2D);
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
