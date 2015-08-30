#ifndef WPLOT_OHLCBAR2D_H_
#define WPLOT_OHLCBAR2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/FinancialItem2D.h"
#include "wplot/OHLC.h"
#include <QPointF>
#include <QColor>
#include <QPen>
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT OHLCBar2D : public FinancialItem2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<OHLCBar2D> Ptr;

public:

	OHLCBar2D();
	virtual ~OHLCBar2D() = default;
	void setPositiveColor(const QColor &color);
	void setNegativeColor(const QColor &color);
	void setColor(const QColor &positive, const QColor &negative);
	void setLineWidth(const double &width);
	void setStyle(const Qt::PenStyle &style);
	void setTickWidth(const double &width);

public:

	virtual void draw(Plot2D *plot);

private:

	double m_lineWidth;
	double m_tickWidth;
	QColor m_lineColor;
	QColor m_positiveColor;
	QColor m_negativeColor;
	Qt::PenStyle m_lineStyle;
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
