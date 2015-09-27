#ifndef WPLOT_CARTESIANBARGRAPH2D_H_
#define WPLOT_CARTESIANBARGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/CartesianScalarGraph2D.h"
#include <QColor>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CartesianBarGraph2D : public CartesianScalarGraph2D
{
public:

	typedef std::shared_ptr<CartesianBarGraph2D> Ptr;

public:

	CartesianBarGraph2D();
	virtual ~CartesianBarGraph2D() = default;
	void setBarLineColor(const QColor &color);
	void setBarLineWidth(const double &width);
	void setBarLineStyle(const Qt::PenStyle &style);
	void setBarColor(const QColor &color);
	void enableBottomBarLine(const bool &enable);
	void setBarWidth(const double &width);

public:

	virtual void draw(Plot2D *plot);

private:

	QColor m_lineColor;
	QColor m_fillColor;
	double m_lineWidth;
	double m_barWidth;
	Qt::PenStyle m_lineStyle;
	QPen m_pen;
	QBrush m_brush;
	bool m_bottomLineEnabled;
};

} // namesapce WPlot

#endif // WPLOT_CARTESIANBARGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CartesianBarGraph2D
 *
 * This class allows to specify a line graph. In a line graph we have many
 * scalar values that are joined by segments. It's possibile to specify the
 * style of the segments.
 *
 * @image html barplot.svg "Black-white barplot example."
 */
