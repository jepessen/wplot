#ifndef WPLOT_FINANCIALITEM2D_H_
#define WPLOT_FINANCIALITEM2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Item2D.h"
#include "wplot/OHLC.h"
#include <memory>

namespace WPlot {

class Plot2D;

class WPLOTSHARED_EXPORT FinancialItem2D : public Item2D
{

public:

	/** Shared pointer to the class. */
	typedef std::shared_ptr<FinancialItem2D> Ptr;

public:

	FinancialItem2D();
	virtual ~FinancialItem2D() = default;
	void setOpenValue(const double &value);
	void setHighValue(const double &value);
	void setLowValue(const double &value);
	void setCloseValue(const double &value);
	void setOHLC(const double &open, const double &high, const double &low, const double &close);
	void setOHLC(const OHLC &ohlc);
	void setXValue(const double &value);

protected:

	double m_xValue;
	OHLC m_values;
};

} // namespace WPlot

#endif // WPLOT_FINANCIALITEM2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::FinancialItem2D
 *
 * This is a base class used to define properties of all financial item. A
 * financial item shows OHLC data (Open, High, Low, Close).
 */
