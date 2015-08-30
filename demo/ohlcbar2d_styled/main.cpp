#include "wplot/Plot2D.h"
#include "wplot/OHLCBar2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple OHLCBar2D inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::OHLCBar2D::Ptr ohlc(new WPlot::OHLCBar2D);
	// Here we use the plot coordinate system
	ohlc->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	ohlc->setOHLC(2, 4, 1, 3);
	ohlc->setXValue(3);
	ohlc->setPositiveColor(Qt::red);
	ohlc->setLineWidth(2.0);
	ohlc->setTickWidth(30);
	ohlc->setStyle(Qt::DashDotLine);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(ohlc);
	plot2D->show();
	return a.exec();
}