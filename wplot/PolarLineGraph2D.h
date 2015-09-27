#ifndef WPLOT_POLARLINEGRAPH2D_H_
#define WPLOT_POLARLINEGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/PolarScalarGraph2D.h"
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT PolarLineGraph2D : public PolarScalarGraph2D
{
public:

	typedef std::shared_ptr<PolarLineGraph2D> Ptr;

public:

	PolarLineGraph2D();
	virtual ~PolarLineGraph2D() = default;
	void setLineColor(const QColor &color);
	void setLineWidth(const double &width);
	void setLineStyle(const Qt::PenStyle &style);
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
	Qt::PenStyle m_style;
	QPen m_pen;
};

} // namesapce WPlot

#endif // WPLOT_POLARLINEGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::PolarLineGraph2D
 *
 * This class allows to specify a line graph. In a line graph we have many
 * scalar values that are joined by segments. It's possibile to specify the
 * style of the segments.
 */
