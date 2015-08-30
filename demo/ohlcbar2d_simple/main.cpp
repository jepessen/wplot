#include "wplot/Plot2D.h"
#include "wplot/OHLCBar2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple OHLCBar2D inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::OHLCBar2D::Ptr ohlcWidget(new WPlot::OHLCBar2D);
	WPlot::OHLCBar2D::Ptr ohlcPlot(new WPlot::OHLCBar2D);
	// By default widget coordinate system is used
	ohlcWidget->setOHLC(400, 60, 500, 100);
	ohlcWidget->setXValue(100.0);
	// Here we use the plot coordinate system
	ohlcPlot->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	ohlcPlot->setOHLC(3, 4, 1, 2);
	ohlcPlot->setXValue(3);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(ohlcWidget);
	plot2D->addItem(ohlcPlot);
	plot2D->show();
	return a.exec();
}
