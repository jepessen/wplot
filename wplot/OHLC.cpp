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

void OHLC::setOpen(const double &value) {
	m_open = value;
}

void OHLC::setHigh(const double &value) {
	m_high = value;
}

void OHLC::setLow(const double &value) {
	m_low = value;
}

void OHLC::setClose(const double &value) {
	m_close = value;
}

void OHLC::set(const double &open, const double &high, const double &low, const double &close) {
	m_open = open;
	m_high = high;
	m_low = low;
	m_close = close;
}

double OHLC::getOpen() const {
	return m_open;
}

double OHLC::getHigh() const {
	return m_high;
}

double OHLC::getLow() const {
	return m_low;
}

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
