#ifndef WPLOT_OHLC_H_
#define WPLOT_OHLC_H_

#include "wplot/WPlotGlobal.h"
#include <memory>
#include <ostream>

namespace WPlot {


class WPLOTSHARED_EXPORT OHLC
{
public:

	typedef std::shared_ptr<OHLC> Ptr;

public:

	OHLC();
	OHLC(const double &open, const double &high, const double &low, const double &close);
	virtual ~OHLC() = default;

	void setOpen(const double &value);
	void setHigh(const double &value);
	void setLow(const double &value);
	void setClose(const double &value);
	void set(const double &open, const double &high, const double &low, const double &close);
	double getOpen() const;
	double getHigh() const;
	double getLow() const;
	double getClose() const;

private:

	double m_open;
	double m_high;
	double m_low;
	double m_close;
};

typedef struct OHLCPoint {
	double x;
	OHLC ohlc;
	OHLCPoint(){};
	OHLCPoint(const double &ix, const OHLC &iohlc) :
		x(ix),
		ohlc(iohlc){}
} OHLCPoint;

} // namespace WPlot

std::ostream& operator<<(std::ostream& ss, const WPlot::OHLC &ohlc);

#endif // WPLOT_OHLC_H_

///////////////////////////////////////////////////////////////////////////////
// DOCUMENTATION                                                             //
///////////////////////////////////////////////////////////////////////////////

/**
 * @class WPlot::OHLCBar2D
 *
 * This class allows to plot a circle inside the plot. The circle has a fixed
 * radius and the pivot represent the center.
 */
