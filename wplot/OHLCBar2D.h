#ifndef WPLOT_OHLCBAR2D_H_
#define WPLOT_OHLCBAR2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include <QPointF>
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT OHLCBar2D : public Item2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<OHLCBar2D> Ptr;

	typedef struct {
		double open;
		double high;
		double low;
		double close;
	} Values;

public:

	OHLCBar2D();
	virtual ~OHLCBar2D() = default;
	void setPositiveColor(const QColor &color);
	void setNegativeColor(const QColor &color);
	void setColor(const QColor &positive, const QColor &negative);
	void setLineWidth(const double &width);
	void setStyle(const Qt::PenStyle &style);
	void setTickWidth(const double &width);
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
	double m_tickWidth;
	double m_xValue;
	QColor m_lineColor;
	QColor m_positiveColor;
	QColor m_negativeColor;
	Qt::PenStyle m_lineStyle;
	Values m_values;
	QPen m_pen;
};

} // namespace WPlot

#endif // WPLOT_OHLCBAR2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::OHLCBar2D
 *
 * This class allows to plot a circle inside the plot. The circle has a fixed
 * radius and the pivot represent the center.
 */
