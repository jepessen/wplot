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
 * @class WPlot::CandleStick2D
 *
 * a Candlestick is a graphic item used in financial graphs used to show
 * OHLC (Open, High, Low, Close) data.
 *
 * The item is shown in the image. It's formed by a vertical line and a
 * rectangle. Line extrema defines high and low values, while upper and
 * lower rectangle edges represent open and close values. The open value can
 * be lower or higher than close value. In one case the item will have a
 * defined color, in the other case another color.
 *
 * @image html candlestick.svg "Candlestick"
 */
