#include "wplot/Plot2D.h"
#include "wplot/OHLCGraph2D.h"
#include "wplot/Grid2D.h"
#include <QApplication>
#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
	std::cout << "Simple circle inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::OHLCGraph2D::Ptr ohlcGraph(new WPlot::OHLCGraph2D);
	WPlot::Grid2D::Ptr grid(new WPlot::Grid2D);
	for (double x = 0.0; x < 8.0; x += 0.2) {
		const double open = sin(x * 0.6) + 2;
		const double high = sin(x * 0.4) + 3;
		const double low = sin(x * 0.8) - 2;
		const double close = sin(x * 0.7) - 1;
		ohlcGraph->appendOHLC(x, open, high, low, close);
	}
	ohlcGraph->setColor(Qt::green, Qt::red);
	ohlcGraph->setTickWidth(8);
	ohlcGraph->setLineWidth(2);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-1, 8.5, -4.0, 4.0);
	plot2D->addGraph(ohlcGraph);
	plot2D->addGrid(grid);
	plot2D->show();
	return a.exec();
}
