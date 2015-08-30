#ifndef WPLOT_CANDLESTICK2D_H_
#define WPLOT_CANDLESTICK2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/FinancialItem2D.h"
#include "wplot/OHLC.h"
#include <QPointF>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CandleStick2D : public FinancialItem2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<CandleStick2D> Ptr;

public:

	CandleStick2D();
	virtual ~CandleStick2D() = default;
	void setBarPositiveColor(const QColor &color);
	void setBarNegativeColor(const QColor &color);
	void setBarColor(const QColor &positive, const QColor &negative);
	void setLineColor(const QColor &color);
	void setLineWidth(const double &width);
	void setLineStyle(const Qt::PenStyle &style);
	void setBarWidth(const double &width);

public:

	virtual void draw(Plot2D *plot);

private:

	double m_lineWidth;
	double m_barWidth;
	QColor m_lineColor;
	QColor m_positiveColor;
	QColor m_negativeColor;
	Qt::PenStyle m_lineStyle;
	QPen m_pen;
	QBrush m_brush;
};

} // namespace WPlot

#endif // WPLOT_CANDLESTICK2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::Circle
 *
 * This class allows to plot a circle inside the plot. The circle has a fixed
 * radius and the pivot represent the center.
 */
