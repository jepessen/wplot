#include "wplot/PolarPlot2D.h"
#include "wplot/PolarGrid2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Basic grid demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::PolarPlot2D* plot2D(new WPlot::PolarPlot2D);
	WPlot::PolarGrid2D::Ptr grid(new WPlot::PolarGrid2D);
	plot2D->setPadding(15, WPlot::Padding::PIXELS);
	plot2D->setRadiusLimits(0, 5);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
