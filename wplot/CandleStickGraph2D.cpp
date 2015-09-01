#include "wplot/CandleStickGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CandleStickGraph2D::CandleStickGraph2D() :
	FinancialGraph2D(),
	m_candlestick() {
	m_candlestick.setPivotCoordinates(Item2D::COORDINATE_PLOT, Item2D::AXIS_BOTH);
}

/**
 * Set the color that the candlestick must assume when positive (close > open).
 *
 * @param[in] color Color.
 */
void CandleStickGraph2D::setBarPositiveColor(const QColor &color) {
	m_candlestick.setBarPositiveColor(color);
}

/**
 * Set the color that the candlestick must assume when negative (close < open).
 *
 * @param[in] color Color.
 */
void CandleStickGraph2D::setBarNegativeColor(const QColor &color) {
	m_candlestick.setBarNegativeColor(color);
}

/**
 * Set the color that the candlestick must assume when positive and negative.
 *
 * @param[in] positive Color assumed when positive.
 * @param[in] negative Color assumed when negative.
 */
void CandleStickGraph2D::setBarColor(const QColor &positive, const QColor &negative) {
	m_candlestick.setBarColor(positive, negative);
}

/**
 * Set the candlestick line color.
 *
 * @param[in] color Color.
 */
void CandleStickGraph2D::setLineColor(const QColor &color) {
	m_candlestick.setLineColor(color);
}

/**
 * Set the candlestick line width.
 *
 * @param[in] width Width.
 */
void CandleStickGraph2D::setLineWidth(const double &width) {
	m_candlestick.setLineWidth(width);
}

/**
 * Set the candlestick line style.
 *
 * @param[in] style Style.
 */
void CandleStickGraph2D::setLineStyle(const Qt::PenStyle &style) {
	m_candlestick.setLineStyle(style);
}

/**
 * Set the candlestick bar width.
 *
 * @param[in] width Width.
 */
void CandleStickGraph2D::setBarWidth(const double &width) {
	m_candlestick.setBarWidth(width);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the graph.
 *
 * @param[in] plot Plot2D where graph must be plotted.
 */
void CandleStickGraph2D::draw(Plot2D *plot) {
	m_candlestick.setDrawingInPaddingArea(true);
	for (auto& it : m_data) {
		m_candlestick.setXValue(it.x);
		m_candlestick.setOHLC(it.ohlc);
		m_candlestick.draw(plot);
	}
}

} // namespace WPlot
