#include "wplot/OHLCGraph2D.h"
#include "wplot/Plot2D.h"

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

OHLCGraph2D::OHLCGraph2D() :
	FinancialGraph2D(),
	m_ohlcBar()
{
	m_ohlcBar.setPivotCoordinates(Item2D::COORDINATE_PLOT, Item2D::AXIS_BOTH);
}

void OHLCGraph2D::setPositiveColor(const QColor &color) {
	m_ohlcBar.setPositiveColor(color);
}

void OHLCGraph2D::setNegativeColor(const QColor &color) {
	m_ohlcBar.setNegativeColor(color);
}

void OHLCGraph2D::setColor(const QColor &positive, const QColor &negative) {
	m_ohlcBar.setColor(positive, negative);
}

void OHLCGraph2D::setLineWidth(const double &width) {
	m_ohlcBar.setLineWidth(width);
}

void OHLCGraph2D::setStyle(const Qt::PenStyle &style) {
	m_ohlcBar.setStyle(style);
}

void OHLCGraph2D::setTickWidth(const double &width) {
	m_ohlcBar.setTickWidth(width);
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

void OHLCGraph2D::draw(Plot2D *plot) {
	m_ohlcBar.setDrawingInPaddingArea(true);
	for (auto& it : m_data) {
		m_ohlcBar.setXValue(it.x);
		m_ohlcBar.setOHLC(it.ohlc);
		m_ohlcBar.draw(plot);
	}
}

} // namespace WPlot
