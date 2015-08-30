#include "wplot/OHLCBar2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

OHLCBar2D::OHLCBar2D() :
	Item2D(),
	m_lineWidth(1.0),
	m_tickWidth(10.0),
	m_xValue(0.0),
	m_lineColor(Qt::black),
	m_positiveColor(Qt::white),
	m_negativeColor(Qt::black),
	m_lineStyle(Qt::SolidLine),
	m_values()
{
	m_pen.setColor(m_lineColor);
	m_pen.setWidthF(m_lineWidth);
	m_pen.setStyle(m_lineStyle);
	setOHLC(0.0, 0.0, 0.0, 0.0);
}

void OHLCBar2D::setPositiveColor(const QColor &color) {
	m_positiveColor = color;
}

void OHLCBar2D::setNegativeColor(const QColor &color) {
	m_negativeColor = color;
}

void OHLCBar2D::setColor(const QColor &positive, const QColor &negative) {
	setPositiveColor(positive);
	setNegativeColor(negative);
}

void OHLCBar2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

void OHLCBar2D::setStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

void OHLCBar2D::setTickWidth(const double &width) {
	m_tickWidth = width;
}

void OHLCBar2D::setOpenValue(const double &value) {
	m_values.open = value;
}

void OHLCBar2D::setHighValue(const double &value) {
	m_values.high = value;
}

void OHLCBar2D::setLowValue(const double &value) {
	m_values.low = value;
}

void OHLCBar2D::setCloseValue(const double &value) {
	m_values.close = value;
}

void OHLCBar2D::setOHLC(const double &open, const double &high, const double &low, const double &close) {
	m_values.open = open;
	m_values.high = high;
	m_values.low = low;
	m_values.close = close;
}

void OHLCBar2D::setOHLC(const OHLCBar2D::Values &ohlc) {
	m_values = ohlc;
}

void OHLCBar2D::setXValue(const double &value) {
	m_xValue = value;
}

///////////////////////////////////////////////////////////////////////////////
// VIRTUAL PUBLIC SECTION                                                    //
///////////////////////////////////////////////////////////////////////////////

/**
 * Draw the circle in specified plot.
 *
 * @param[in] plot Plot where circle must be drawn.
 */
void OHLCBar2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	if (m_values.close > m_values.open) {
		m_pen.setColor(m_positiveColor);
	} else {
		m_pen.setColor(m_negativeColor);
	}
	painter.setPen(m_pen);
	const double tickWidth = getScaledDimensionX(m_tickWidth, plot);
	const double xValue = getScaledPositionX(m_xValue, plot);
	const QPointF highPoint = getScaledPosition(m_xValue, m_values.high, plot);
	const QPointF lowPoint = getScaledPosition(m_xValue, m_values.low, plot);
	const double openValue = getScaledPositionY(m_values.open, plot);
	const double closeValue = getScaledPositionY(m_values.close, plot);
	painter.drawLine(highPoint, lowPoint);
	painter.drawLine(QLineF(xValue, openValue, xValue - tickWidth, openValue));
	painter.drawLine(QLineF(xValue, closeValue, xValue + tickWidth, closeValue));
}

} // namespace WPlot
