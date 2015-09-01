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

/**
 * Set the open value.
 *
 * @param[in] value Value.
 */
void FinancialItem2D::setOpenValue(const double &value) {
	m_values.setOpen(value);
}

/**
 * Set the high value.
 *
 * @param[in] value Value.
 */
void FinancialItem2D::setHighValue(const double &value) {
	m_values.setHigh(value);
}

/**
 * Set the low value.
 *
 * @param[in] value Value.
 */
void FinancialItem2D::setLowValue(const double &value) {
	m_values.setLow(value);
}

/**
 * Set the close value.
 *
 * @param[in] value Value.
 */
void FinancialItem2D::setCloseValue(const double &value) {
	m_values.setClose(value);
}

/**
 * Set all values at once.
 *
 * @param[in] open Open value.
 * @param[in] high High value.
 * @param[in] low  Low value.
 * @param[in] close Close value.
 */
void FinancialItem2D::setOHLC(const double &open, const double &high, const double &low, const double &close) {
	m_values.set(open, high, low, close);
}

/**
 * Set the item from OHLC item.
 *
 * @param[in] ohlc OHLC values.
 */
void FinancialItem2D::setOHLC(const OHLC &ohlc) {
	m_values = ohlc;
}

/**
 * Set the X coordinate for the item.
 *
 * @param[in] value X value.
 */
void FinancialItem2D::setXValue(const double &value) {
	m_xValue = value;
}

} // namespace WPlot
