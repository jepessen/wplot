#include "wplot/OHLCBar2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

OHLCBar2D::OHLCBar2D() :
	FinancialItem2D(),
	m_lineWidth(1.0),
	m_tickWidth(10.0),
	m_lineColor(Qt::black),
	m_positiveColor(Qt::white),
	m_negativeColor(Qt::black),
	m_lineStyle(Qt::SolidLine)
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_pen.setStyle(m_lineStyle);
}

/**
 * Set the OHLC bar color when the close value is higher than the open
 * value.
 *
 * @param[in] color Color.
 */
void OHLCBar2D::setPositiveColor(const QColor &color) {
	m_positiveColor = color;
}

/**
 * Set the OHLC bar color when the close value is lower than the open
 * value.
 *
 * @param[in] color Color.
 */
void OHLCBar2D::setNegativeColor(const QColor &color) {
	m_negativeColor = color;
}

/**
 * Set OHLC bar colors that must be set when positive and when negative.
 *
 * @param[in] positive Color used when candlestick is positive.
 * @param[in] negative Color used when candlestick is negative.
 */
void OHLCBar2D::setColor(const QColor &positive, const QColor &negative) {
	setPositiveColor(positive);
	setNegativeColor(negative);
}

/**
 * Set line width.
 *
 * @param[in] width Width.
 */
void OHLCBar2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

/**
 * Set the style of line.
 *
 * @param[in] style Style.
 */
void OHLCBar2D::setStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

/**
 * Set width of ticks.
 *
 * @param[in] width Width.
 */
void OHLCBar2D::setTickWidth(const double &width) {
	m_tickWidth = width;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the OHLC bar in specified plot.
 *
 * @param[in] plot Plot where item must be drawn.
 */
void OHLCBar2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	if (m_values.getClose() > m_values.getOpen()) {
		m_pen.setColor(m_positiveColor);
	} else {
		m_pen.setColor(m_negativeColor);
	}
	painter.setPen(m_pen);
	const double tickWidth = getScaledDimensionX(m_tickWidth, plot);
	const double xValue = getScaledPositionX(m_xValue, plot);
	const QPointF highPoint = getScaledPosition(m_xValue, m_values.getHigh(), plot);
	const QPointF lowPoint = getScaledPosition(m_xValue, m_values.getLow(), plot);
	const double openValue = getScaledPositionY(m_values.getOpen(), plot);
	const double closeValue = getScaledPositionY(m_values.getClose(), plot);
	painter.drawLine(highPoint, lowPoint);
	painter.drawLine(QLineF(xValue, openValue, xValue - tickWidth, openValue));
	painter.drawLine(QLineF(xValue, closeValue, xValue + tickWidth, closeValue));
}

} // namespace WPlot
