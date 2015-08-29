#include "wplot/Plot2D.h"
#include "wplot/Ticks2D.h"
#include "wplot/Axes2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Styled text inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Ticks2D::Ptr ticks(new WPlot::Ticks2D);
	WPlot::Axes2D::Ptr axes(new WPlot::Axes2D);
	ticks->setOrigin(150.0, 200.0);
	ticks->setPrimaryTickLength(20);
	ticks->setEnableLabels(true);
	axes->setTicks(ticks);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3.3, 7.5, -2, 4.3);
	plot2D->addAxes(axes);
	plot2D->show();
	return a.exec();
}
