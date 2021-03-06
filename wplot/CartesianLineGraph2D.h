#ifndef WPLOT_CARTESIANLINEGRAPH2D_H_
#define WPLOT_CARTESIANLINEGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/CartesianScalarGraph2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CartesianLineGraph2D : public CartesianScalarGraph2D
{
public:

	typedef std::shared_ptr<CartesianLineGraph2D> Ptr;

public:

	CartesianLineGraph2D();
	virtual ~CartesianLineGraph2D() = default;
	void setLineColor(const QColor &color);
	void setLineWidth(const double &width);
	void setFillColor(const QColor &color);
	void setFillYCoordinate(const double &coordinate);

public:

	virtual void draw(Plot2D *plot);

private:

	void drawSolidColorLine(Plot2D *plot);
	void drawGradientLine(Plot2D *plot);
	void drawFilling(Plot2D *plot);

private:

	QColor m_lineColor;
	QColor m_fillColor;
	double m_lineWidth;
	double m_fillColorYCoordinate;
	QPen m_pen;
};

} // namesapce WPlot

#endif // WPLOT_CARTESIANLINEGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CartesianLineGraph2D
 *
 * This class allows to specify a line graph. In a line graph we have many
 * scalar values that are joined by segments. It's possibile to specify the
 * style of the segments.
 */
