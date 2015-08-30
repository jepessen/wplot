#ifndef WPLOT_CANDLESTICK2D_H_
#define WPLOT_CANDLESTICK2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QColor>
#include <QPen>
#include <QBrush>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CandleStick2D : public Item2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<CandleStick2D> Ptr;

	typedef struct {
		double open;
		double high;
		double low;
		double close;
	} Values;

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
	void setOpenValue(const double &value);
	void setHighValue(const double &value);
	void setLowValue(const double &value);
	void setCloseValue(const double &value);
	void setOHLC(const double &open, const double &high, const double &low, const double &close);
	void setOHLC(const Values &ohlc);
	void setXValue(const double &value);

public:

	virtual void draw(Plot2D *plot);

private:

	double m_lineWidth;
	double m_barWidth;
	double m_xValue;
	QColor m_lineColor;
	QColor m_positiveColor;
	QColor m_negativeColor;
	Qt::PenStyle m_lineStyle;
	Values m_values;
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
