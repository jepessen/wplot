#include "wplot/FinancialGraph2D.h"

namespace WPlot {

FinancialGraph2D::FinancialGraph2D() :
	Graph2D()
{}

void FinancialGraph2D::setData(const Data &data) {
	m_data = data;
}

void FinancialGraph2D::appendOHLC(const OHLCPoint &ohlc) {
	m_data.append(ohlc);
}

void FinancialGraph2D::appendOHLC(const double &x, const OHLC &ohlc) {
	m_data.append(OHLCPoint(x, ohlc));
}

void FinancialGraph2D::appendOHLC(const double &x, const double &open, const double &high, const double &low, const double &close) {
	m_data.append(OHLCPoint(x, OHLC(open, high, low, close)));
}

void FinancialGraph2D::insertOHLC(const int &index, const OHLCPoint &ohlc) {
	m_data.insert(index, ohlc);
}

void FinancialGraph2D::insertOHLC(const int &index, const double &x, const OHLC &ohlc) {
	m_data.insert(index, OHLCPoint(x, ohlc));
}

void FinancialGraph2D::insertOHLC(const int &index, const double &x, const double &open, const double &high, const double &low, const double &close) {
	m_data.insert(index, OHLCPoint(x, OHLC(open, high, low, close)));
}

void FinancialGraph2D::clear() {
	m_data.clear();
}

} // namespace WPlot
