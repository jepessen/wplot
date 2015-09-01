#include "wplot/Plot2D.h"
#include "wplot/CandleStick2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple CandleStick2D inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::CandleStick2D::Ptr candlestickWidget(new WPlot::CandleStick2D);
	WPlot::CandleStick2D::Ptr candlestickPlot(new WPlot::CandleStick2D);
	// By default widget coordinate system is used
	candlestickWidget->setOHLC(100, 60, 500, 400);
	candlestickWidget->setXValue(100.0);
	// Here we use the plot coordinate system
	candlestickPlot->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_X);
	candlestickPlot->setOHLC(2, 4, 1, 3);
	candlestickPlot->setXValue(3);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(candlestickWidget);
	plot2D->addItem(candlestickPlot);
	plot2D->show();
	return a.exec();
}
