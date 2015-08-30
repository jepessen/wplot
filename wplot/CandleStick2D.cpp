#include "wplot/CandleStick2D.h"
#include "wplot/Plot2D.h"
#include <QPainter>

namespace WPlot {

///////////////////////////////////////////////////////////////////////////////
// PUBLIC SECTION                                                            //
///////////////////////////////////////////////////////////////////////////////

CandleStick2D::CandleStick2D() :
	Item2D(),
	m_lineWidth(1.0),
	m_barWidth(10.0),
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
	m_brush.setStyle(Qt::SolidPattern);
	setOHLC(0.0, 0.0, 0.0, 0.0);
}

void CandleStick2D::setBarPositiveColor(const QColor &color) {
	m_positiveColor = color;
}

void CandleStick2D::setBarNegativeColor(const QColor &color) {
	m_negativeColor = color;
}

void CandleStick2D::setBarColor(const QColor &positive, const QColor &negative) {
	setBarPositiveColor(positive);
	setBarNegativeColor(negative);
}

void CandleStick2D::setLineColor(const QColor &color) {
	m_lineColor = color;
	m_pen.setColor(color);
}

void CandleStick2D::setLineWidth(const double &width) {
	m_lineWidth = width;
	m_pen.setWidthF(width);
}

void CandleStick2D::setLineStyle(const Qt::PenStyle &style) {
	m_lineStyle = style;
	m_pen.setStyle(style);
}

void CandleStick2D::setBarWidth(const double &width) {
	m_barWidth = width;
}

void CandleStick2D::setOpenValue(const double &value) {
	m_values.open = value;
}

void CandleStick2D::setHighValue(const double &value) {
	m_values.high = value;
}

void CandleStick2D::setLowValue(const double &value) {
	m_values.low = value;
}

void CandleStick2D::setCloseValue(const double &value) {
	m_values.close = value;
}

void CandleStick2D::setOHLC(const double &open, const double &high, const double &low, const double &close) {
	m_values.open = open;
	m_values.high = high;
	m_values.low = low;
	m_values.close = close;
}

void CandleStick2D::setOHLC(const CandleStick2D::Values &ohlc) {
	m_values = ohlc;
}

void CandleStick2D::setXValue(const double &value) {
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
void CandleStick2D::draw(Plot2D *plot) {
	QPainter painter(plot);
	plot->initializePainter(painter);
	limitPainterInPaddingArea(painter, plot);
	double rectTop;
	double rectBottom;
	painter.setPen(m_pen);
	if (m_values.close > m_values.open) {
		m_brush.setColor(m_positiveColor);
		rectTop = getScaledPositionY(m_values.close, plot);
		rectBottom = getScaledPositionY(m_values.open, plot);
	} else {
		m_brush.setColor(m_negativeColor);
		rectTop = getScaledPositionY(m_values.open, plot);
		rectBottom = getScaledPositionY(m_values.close, plot);
	}
	painter.setBrush(m_brush);
	const double barWidth = getScaledDimensionX(m_barWidth, plot);
	const QPointF highPoint = getScaledPosition(m_xValue, m_values.high, plot);
	const QPointF lowPoint = getScaledPosition(m_xValue, m_values.low, plot);
	const double rectLeft = getScaledPositionX(m_xValue, plot) - 0.5 * barWidth;
	const QRectF rect(rectLeft, rectTop, barWidth, rectBottom - rectTop);
	painter.drawLine(highPoint, lowPoint);
	painter.drawRect(rect);
}

} // namespace WPlot
