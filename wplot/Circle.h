#ifndef WPLOT_CIRCLE_H_
#define WPLOT_CIRCLE_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT Circle : public Item2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<Circle> Ptr;

public:

	Circle();
	virtual ~Circle() = default;
	void setRadius(const double &radius);
	void setLineColor(const QColor &color);
	void setFillColor(const QColor &color);
	void setLineWidth(const double &width);
	void setLineStyle(const Qt::PenStyle &style);

public:

	virtual void draw(Plot2D *plot);

private:

	double m_radius;
	QColor m_fillColor;
	QColor m_lineColor;
	Qt::PenStyle m_lineStyle;
	double m_lineWidth;
	QPen m_pen;
	QBrush m_brush;
};

} // namespace WPlot

#endif // WPLOT_CIRCLE_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Circle
 *
 * This class allows to plot a circle inside the plot. The circle has a fixed
 * radius and the pivot represent the center.
 */
