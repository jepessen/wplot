#ifndef WPLOT_OHLCGRAPH2D_H_
#define WPLOT_OHLCGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/FinancialGraph2D.h"
#include "wplot/Item2D.h"
#include "wplot/OHLCBar2D.h"
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT OHLCGraph2D : public FinancialGraph2D
{

public:

	typedef std::shared_ptr<OHLCGraph2D> Ptr;

public:
	OHLCGraph2D();
	virtual ~OHLCGraph2D() = default;
	void setPositiveColor(const QColor &color);
	void setNegativeColor(const QColor &color);
	void setColor(const QColor &positive, const QColor &negative);
	void setLineWidth(const double &width);
	void setStyle(const Qt::PenStyle &style);
	void setTickWidth(const double &width);

public:

	virtual void draw(Plot2D *plot);

private:

	OHLCBar2D m_ohlcBar;
};

} // namespace WPlot

#endif // WPLOT_OHLCGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::OHLCGraph2D
 *
 * This class allows to define a graph in which a set of ohlc bars are drawn
 * in order to represent set financial data.
 *
 * @image html ohlcbar_plot.svg "OHLC graph."
 */
