#include "wplot/Plot2D.h"
#include "wplot/Text2D.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Styled text inset demo" << std::endl;
	QApplication a(argc, argv);
	WPlot::Plot2D* plot2D(new WPlot::Plot2D);
	WPlot::Text2D::Ptr text(new WPlot::Text2D);
	const QFont font("Helvetica");
	text->setPivot(150.0, 200.0);
	text->setText("Widget Text sample.");
	text->setColor(Qt::red);
	text->setFont(font);
	text->setFontSize(30);
	plot2D->setPadding(25, WPlot::Padding::PIXELS);
	plot2D->setPlotLimits(-3, 7.5, -2, 4.3);
	plot2D->addItem(text);
	plot2D->show();
	return a.exec();
}
