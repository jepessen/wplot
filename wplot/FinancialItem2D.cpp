#include "wplot/FinancialItem2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

FinancialItem2D::FinancialItem2D() :
	Item2D(),
	m_xValue(0.0),
	m_values()
{}

void FinancialItem2D::setOpenValue(const double &value) {
	m_values.setOpen(value);
}

void FinancialItem2D::setHighValue(const double &value) {
	m_values.setHigh(value);
}

void FinancialItem2D::setLowValue(const double &value) {
	m_values.setLow(value);
}

void FinancialItem2D::setCloseValue(const double &value) {
	m_values.setClose(value);
}

void FinancialItem2D::setOHLC(const double &open, const double &high, const double &low, const double &close) {
	m_values.set(open, high, low, close);
}

void FinancialItem2D::setOHLC(const OHLC &ohlc) {
	m_values = ohlc;
}

void FinancialItem2D::setXValue(const double &value) {
	m_xValue = value;
}

} // namespace WPlot
