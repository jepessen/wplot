#include "wplot/OHLC.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

OHLC::OHLC() :
	m_open(double()),
	m_high(double()),
	m_low(double()),
	m_close(double()) {
}

OHLC::OHLC(const double &open, const double &high, const double &low, const double &close) :
	m_open(open),
	m_high(high),
	m_low(low),
	m_close(close) {
}

/**
 * Set the open value.
 *
 * @param[in] value Value.
 */
void OHLC::setOpen(const double &value) {
	m_open = value;
}

/**
 * Set the high value.
 *
 * @param[in] value Value.
 */
void OHLC::setHigh(const double &value) {
	m_high = value;
}

/**
 * Set the low value.
 *
 * @param[in] value Value.
 */
void OHLC::setLow(const double &value) {
	m_low = value;
}

/**
 * Set the close value.
 *
 * @param[in] value Value.
 */
void OHLC::setClose(const double &value) {
	m_close = value;
}

/**
 * Defines all values at the same time.
 *
 * @param[in] open Open value.
 * @param[in] high High value.
 * @param[in] low Low value.
 * @param[in] close Close value.
 */
void OHLC::set(const double &open, const double &high, const double &low, const double &close) {
	m_open = open;
	m_high = high;
	m_low = low;
	m_close = close;
}

/**
 * Retrieve the open value.
 *
 * @return Value.
 */
double OHLC::getOpen() const {
	return m_open;
}

/**
 * Retrieve the high value.
 *
 * @return Value.
 */
double OHLC::getHigh() const {
	return m_high;
}

/**
 * Retrieve the ;pw value.
 *
 * @return Value.
 */
double OHLC::getLow() const {
	return m_low;
}

/**
 * Retrieve the close value.
 *
 * @return Value.
 */
double OHLC::getClose() const {
	return m_close;
}

///////////////////////////////////////////////////////////////////////////////
// NON MEMBER OPERATORS SECTION                                              //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& ss, const OHLC &ohlc) {
	ss << '(' << ohlc.getOpen() << ", " << ohlc.getHigh() << ", "
	<< ohlc.getLow() << ", " << ohlc.getClose() << ')';
	return ss;
}

} // namespace WPlot
