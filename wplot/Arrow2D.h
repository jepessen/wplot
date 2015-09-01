#ifndef WPLOT_ARROW2D_H_
#define WPLOT_ARROW2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QSizeF>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT Arrow2D : public Item2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<Arrow2D> Ptr;

public:

	Arrow2D();
	virtual ~Arrow2D() = default;
	void setFinalPoint(const QPointF &point);
	void setFinalPoint(const double &x, const double &y);
	void setLine(const QPointF &initialPoint, const QPointF &finalPoint);
	void setLine(const double &x1, const double &y1, const double &x2, const double &y2);
	void setLineColor(const QColor &color);
	void setLineWidth(const double &width);
	void setLineStyle(const Qt::PenStyle &style);
	void setArrowFillColor(const QColor &color);
	void setArrowLineColor(const QColor &color);
	void setArrowLineWidth(const double &width);
	void setArrowLineStyle(const Qt::PenStyle &style);
	void setArrowLength(const double &length);
	void setArrowWidth(const double &width);
	void setArrowDimensions(const double &width, const double &length);
	double getArrowLength() const;
	double getArrowWidth() const;

public:

	virtual void draw(Plot2D *plot);

private:

	void drawLine(QPainter &painter, Plot2D *plot);
	void drawArrow(QPainter &arrow, Plot2D *plot);

private:

	QPointF m_finalPoint;
	double m_lineWidth;
	double m_arrowLineWidth;
	double m_arrowWidth;
	double m_arrowLength;
	QColor m_lineColor;
	QColor m_arrowLineColor;
	QColor m_arrowFillColor;
	Qt::PenStyle m_lineStyle;
	Qt::PenStyle m_arrowLineStyle;
	QPen m_linePen;
	QPen m_arrowLinePen;
	QBrush m_arrowBrush;
};

} // namespace WPlot

#endif // WPLOT_ARROW2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Arrow2D
 *
 * The class allows to draw arrows inside a plot. The arrow is defined by
 * a line and a endcap that represents the arrows itself. It's possibile to
 * define arrows dimensions in addition to other usual parameters like width
 * and colors.
 *
 * @image html arrow.svg "Arrow dimension setting."
 */
