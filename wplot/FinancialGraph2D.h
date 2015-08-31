#ifndef WPLOT_FINANCIALGRAPH2D_H_
#define WPLOT_FINANCIALGRAPH2D_H_

#include "wplot/WPlotGlobal.h"
#include "wplot/Graph2D.h"
#include "wplot/OHLC.h"
#include <QVector>
#include <memory>

namespace WPlot {

class WPLOTSHARED_EXPORT FinancialGraph2D : public Graph2D
{
public:

	/** Pointer to this class. */
	typedef std::shared_ptr<FinancialGraph2D> Ptr;

	typedef QVector<OHLCPoint> Data;

public:

	FinancialGraph2D();
	virtual ~FinancialGraph2D() = default;
	void setData(const Data &data);
	void appendOHLC(const OHLCPoint &ohlc);
	void appendOHLC(const double &x, const OHLC &ohlc);
	void appendOHLC(const double &x, const double &open, const double &high, const double &low, const double &close);
	void insertOHLC(const int &index, const OHLCPoint &ohlc);
	void insertOHLC(const int &index, const double &x, const OHLC &ohlc);
	void insertOHLC(const int &index, const double &x, const double &open, const double &high, const double &low, const double &close);

public:

	virtual void clear();

protected:

	Data m_data;
};

} // namespace WPlot

#endif // WPLOT_FINANCIALGRAPH2D_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::FinancialGraph2D
 *
 * This class is a base class for all plots that must be set with financial
 * values (OHLC). The base class allows to set data that must be drawn in
 * derived classes.
 */
