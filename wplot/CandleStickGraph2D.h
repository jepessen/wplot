#ifndef WPLOT_CANDLESTICKGRAPH2D_H_
#define WPLOT_CANDLESTICKGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/FinancialGraph2D.h"
#include "wplot/Item2D.h"
#include "wplot/CandleStick2D.h"
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT CandleStickGraph2D : public FinancialGraph2D
{

public:

	typedef std::shared_ptr<CandleStickGraph2D> Ptr;

public:
	CandleStickGraph2D();
	virtual ~CandleStickGraph2D() = default;
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

	CandleStick2D m_candlestick;
};

} // namespace WPlot

#endif // WPLOT_CANDLESTICKGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::CandleStickGraph2D
 *
 * This class allows to define a graph in which a set of candlestick are drawn
 * in order to represent set financial data.
 *
 * @image html candlestick_plot.svg "Candlestick graph."
 */
