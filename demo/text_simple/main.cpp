#include "wplot/Plot2D.h"
#include "wplot/Text2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Simple text inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Text2D::Ptr textWidget(new WPlot::Text2D);
	WPlot::Text2D::Ptr textPlot(new WPlot::Text2D);
	// By default widget coordinate system is used
	textWidget->setPivot(150.0, 200.0);
	textWidget->setText("Widget Text sample.");
	// Here we use the plot coordinate system
	textPlot->setPivotCoordinates(WPlot::Item2D::COORDINATE_PLOT, WPlot::Item2D::AXIS_BOTH);
	textPlot->setDimensionCoordinates(WPlot::Item2D::COORDINATE_WIDGET, WPlot::Item2D::AXIS_BOTH);
	textPlot->setText("Plot Text sample.");
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(textWidget);
	plot2D->addItem(textPlot);
	plot2D->show();
	return a.exec();
}
