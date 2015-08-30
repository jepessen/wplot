#include "wplot/CandleStickGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CandleStickGraph2D::CandleStickGraph2D() :
	FinancialGraph2D(),
	m_candlestick()
{
	m_candlestick.setPivotCoordinates(Item2D::COORDINATE_PLOT, Item2D::AXIS_BOTH);
}

void CandleStickGraph2D::setBarPositiveColor(const QColor &color) {
	m_candlestick.setBarPositiveColor(color);
}

void CandleStickGraph2D::setBarNegativeColor(const QColor &color) {
	m_candlestick.setBarNegativeColor(color);
}

void CandleStickGraph2D::setBarColor(const QColor &positive, const QColor &negative) {
	m_candlestick.setBarColor(positive, negative);
}

void CandleStickGraph2D::setLineColor(const QColor &color) {
	m_candlestick.setLineColor(color);
}

void CandleStickGraph2D::setLineWidth(const double &width) {
	m_candlestick.setLineWidth(width);
}

void CandleStickGraph2D::setLineStyle(const Qt::PenStyle &style) {
	m_candlestick.setLineStyle(style);
}

void CandleStickGraph2D::setBarWidth(const double &width) {
	m_candlestick.setBarWidth(width);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void CandleStickGraph2D::draw(Plot2D *plot) {
	m_candlestick.setDrawingInPaddingArea(true);
	for (auto& it : m_data) {
		m_candlestick.setXValue(it.x);
		m_candlestick.setOHLC(it.ohlc);
		m_candlestick.draw(plot);
	}
}

} // namespace WPlot
