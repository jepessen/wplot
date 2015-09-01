#include "wplot/Plot2D.h"
#include "wplot/CandleStick2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple CandleStick2D inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::CandleStick2D::Ptr candlestick(new WPlot::CandleStick2D);
	// Here we use the plot coordinate system
	candlestick->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	candlestick->setOHLC(2, 4, 1, 3);
	candlestick->setXValue(3);
	candlestick->setBarPositiveColor(Qt::yellow);
	candlestick->setLineColor(Qt::green);
	candlestick->setLineWidth(2.0);
	candlestick->setBarWidth(30);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(candlestick);
	plot2D->show();
	return a.exec();
}
