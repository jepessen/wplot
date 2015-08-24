#ifndef WPLOT_RECTANGLE_H_
#define WPLOT_RECTANGLE_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QSizeF>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT Rectangle : public Item2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<Rectangle> Ptr;

	/**
	 * This enumerator specifies the position of the pivot
	 * related to rectangle.
	 */
	typedef enum {
		PIVOT_BOTTOM_LEFT,
		PIVOT_BOTTOM_CENTER,
		PIVOT_BOTTOM_RIGHT,
		PIVOT_MIDDLE_LEFT,
		PIVOT_MIDDLE_CENTER,
		PIVOT_MIDDLE_RIGHT,
		PIVOT_TOP_LEFT,
		PIVOT_TOP_CENTER,
		PIVOT_TOP_RIGHT,
	} PivotPosition;

public:

	Rectangle();
	virtual ~Rectangle() = default;
	void setDimensions(const QPointF &dimensions);
	void setDimensions(const QSizeF &dimensions);
	void setDimensions(const double &width, const double &height);
	void setPivotPosition(const PivotPosition &position);
	void setLineColor(const QColor &color);
	void setFillColor(const QColor &color);
	void setLineWidth(const double &width);
	void setLineStyle(const Qt::PenStyle &style);

public:

	virtual void draw(Plot2D *plot);

private:

	QPointF getTopLeftPivot(Plot2D *plot) const;

private:

	PivotPosition m_pivotPosition;
	QSizeF m_dimensions;
	QColor m_fillColor;
	QColor m_lineColor;
	Qt::PenStyle m_lineStyle;
	double m_lineWidth;
	QPen m_pen;
	QBrush m_brush;
};

} // namespace WPlot

#endif // WPLOT_RECTANGLE_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Rectangle
 *
 * This allows to draw a rectangle in the plot. The rectangle is specified by
 * its pivot and its dimension.
 */
