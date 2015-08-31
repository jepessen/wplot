#include "wplot/FinancialGraph2D.h"

namespace WPlot {

FinancialGraph2D::FinancialGraph2D() :
	Graph2D()
{}

/**
 * Set data that must be plotted.
 *
 * @param[in] data Data.
 */
void FinancialGraph2D::setData(const Data &data) {
	m_data = data;
}

/**
 * Append an OHLC value.
 *
 * @param[in] ohlc OHLC point.
 */
void FinancialGraph2D::appendOHLC(const OHLCPoint &ohlc) {
	m_data.append(ohlc);
}

/**
 * Append an OHLC value.
 *
 * @param[in] x Coordinate in which data must be shown.
 * @param[in] ohlc OHLC value.
 */
void FinancialGraph2D::appendOHLC(const double &x, const OHLC &ohlc) {
	m_data.append(OHLCPoint(x, ohlc));
}

/**
 * Append an OHLC value.
 *
 * @param[in] x Coordinate in which data must be shown.
 * @param[in] open Open value.
 * @param[in] high High value.
 * @param[in] low Low value.
 * @param[in] close Close value.
 */
void FinancialGraph2D::appendOHLC(const double &x, const double &open, const double &high, const double &low, const double &close) {
	m_data.append(OHLCPoint(x, OHLC(open, high, low, close)));
}

/**
 * Insert an OHLC data in specified data position.
 *
 * @param[in] index Position index.
 * @param[in] ohlc OHLD data.
 */
void FinancialGraph2D::insertOHLC(const int &index, const OHLCPoint &ohlc) {
	m_data.insert(index, ohlc);
}

/**
 * Insert an OHLC data in specified data position.
 *
 * @param[in] index Position index.
 * @param[in] x Coordinate in which data must be shown.
 * @param[in] ohlc OHLC value.
 */
void FinancialGraph2D::insertOHLC(const int &index, const double &x, const OHLC &ohlc) {
	m_data.insert(index, OHLCPoint(x, ohlc));
}

/**
 * Insert an OHLC data in specified data position.
 *
 * @param[in] index Position index.
 * @param[in] x Coordinate in which data must be shown.
 * @param[in] open Open value.
 * @param[in] high High value.
 * @param[in] low Low value.
 * @param[in] close Close value.
 */
void FinancialGraph2D::insertOHLC(const int &index, const double &x, const double &open, const double &high, const double &low, const double &close) {
	m_data.insert(index, OHLCPoint(x, OHLC(open, high, low, close)));
}

void FinancialGraph2D::clear() {
	m_data.clear();
}

} // namespace WPlot
